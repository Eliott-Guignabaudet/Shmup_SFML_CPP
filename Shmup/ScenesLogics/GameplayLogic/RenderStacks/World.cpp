#include "World.h"

#include <functional>
#include <iostream>
#include <Windows.h>
#include <math.h>

#include "../../../Managers/DestructionManager.h"
#include "../../../Managers/Manager.h"
#include "../Character/AIShootVertical.h"
#include "../Character/AiSuicideCharacter.h"
#include "../Character/Player.h"

World::World() : m_activeProjectiles(), m_aiSpawner()
{

}

World::~World()
{
    delete m_pool;
    for (AICharacter* aiCharacter : m_aiSpawner->ActiveCharacters)
    {
        delete aiCharacter;
    }
}


void World::Load()
{
    using namespace std::placeholders;
    m_pool = new ProjectilePool(10);
    auto function = std::bind(&World::ActiveProjectile, this, _1, _2, _3, _4, _5, _6, _7);
    Player player(sf::Vector2f(0, 0), sf::Vector2f(1, 5), 250, 3, function);
    m_player = player;
    m_aiSpawner = new AICharacterSpawner(function);
    
    m_view.reset(sf::FloatRect(-400, -400, 800, 800));
    m_player.Load();
}

void World::Init()
{
    m_player.Init();
    for (AICharacter* character : m_aiSpawner->ActiveCharacters)
    {
        character->Init();
    }
    ARenderStack::Init();
}

void World::Update(sf::Time a_deltaTime)
{
    m_player.Update(a_deltaTime);
    BlockPlayerInWorld();
    m_aiSpawner->Update(a_deltaTime);
    if (m_aiSpawner->IsSpawnerFinished())
    {
        Manager::GetInstance()->LoadScene("GameOver");
    }
    
    
    for (AICharacter* character : m_aiSpawner->ActiveCharacters)
    {
        character->Update(a_deltaTime);


        if (abs(character->getPosition().x) > 400 || abs(character->getPosition().y) > 400)
        {
            RemoveAI(character);
            continue;
        }
        
        sf::Vector2f distance = m_player.getPosition() - character->getPosition();
        distance.x = abs(distance.x);
        distance.y = abs(distance.y);
        float distanceMagnitude = (distance.x + distance.y);
        float minDistance = (character->GetBounds().getRadius() + m_player.GetBounds().getRadius()) * 1.5f;
        if (distanceMagnitude <= minDistance)
        {
            character->TakeDamage();
            if (character->GetIsDead())
            {
                RemoveAI(character);
                m_player.AddScore(100);
            }
            m_player.TakeDamage();
        }
    }
    for (Projectile* projectile : m_activeProjectiles)
    {
        projectile->Update(a_deltaTime);
        std::vector<Projectile*>::iterator index = std::find(m_activeProjectiles.begin(), m_activeProjectiles.end(),projectile);
        if (index == m_activeProjectiles.end())
        {
            continue;
        }
        CheckProjectileCollisions(projectile);
    }
}

void World::CheckProjectileCollisions(Projectile* a_projectile)
{
    if (a_projectile->GetTag() == "Player")
    {
        for (AICharacter* aiCharacter : m_aiSpawner->ActiveCharacters)
        {
            for (int i = 0; i < aiCharacter->GetBounds().getPointCount(); ++i)
            {
                sf::Vector2f absoluteAiCharacterPointPosition = aiCharacter->getTransform().transformPoint(
                    aiCharacter->GetBounds().getTransform().transformPoint(
                        aiCharacter->GetBounds().getPoint(i)));

                sf::FloatRect absoluteProjectileBound = a_projectile->getTransform().transformRect(
                    a_projectile->GetBounds().getTransform().transformRect(
                        a_projectile->GetBounds().getGlobalBounds()
                    ));
                if (absoluteProjectileBound.contains(absoluteAiCharacterPointPosition))
                {
                    aiCharacter->TakeDamage();
                    if (aiCharacter->GetIsDead())
                    {
                        delete aiCharacter;
                        std::vector<AICharacter*>::iterator index = std::find(
                            m_aiSpawner->ActiveCharacters.begin(), m_aiSpawner->ActiveCharacters.end(), aiCharacter);
                        m_aiSpawner->ActiveCharacters.erase(index);
                        m_player.AddScore(100);
                    }
                    DisableProjectile(a_projectile);
                    break;
                }
            }
        }
    }else if (a_projectile->GetTag() == "AI")
    {
        for (int i = 0; i < m_player.GetBounds().getPointCount(); ++i)
        {
            sf::Vector2f absolutePlayerCharacterPointPosition = m_player.getTransform().transformPoint(
                    m_player.GetBounds().getTransform().transformPoint(
                        m_player.GetBounds().getPoint(i)));

            sf::FloatRect absoluteProjectileBound = a_projectile->getTransform().transformRect(
                a_projectile->GetBounds().getTransform().transformRect(
                    a_projectile->GetBounds().getGlobalBounds()
                ));
            if (absoluteProjectileBound.contains(absolutePlayerCharacterPointPosition))
            {
                m_player.TakeDamage();

                DisableProjectile(a_projectile);
            }
        }
    }

    if (a_projectile->getPosition().x < -400 || a_projectile->getPosition().y < -400 || a_projectile->getPosition().x >
        400 || a_projectile->getPosition().y > 400)
    {
        DisableProjectile(a_projectile);
    }
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.setView(m_view);
    target.draw(m_player);
    for (Projectile* projectile : m_activeProjectiles)
    {
        target.draw(*projectile);
    }
    for (AICharacter* character : m_aiSpawner->ActiveCharacters)
    {
        target.draw(*character);
    }
    // sf::CircleShape circle_shape(16);
    // circle_shape.setPosition({0,0});
    // circle_shape.setOrigin(16,16);
    // target.draw(circle_shape);
}

void World::HandleEvent(sf::Event a_event)
{
    ARenderStack::HandleEvent(a_event);
    m_player.HandleEvent(a_event);
    for (Projectile* projectile : m_activeProjectiles)
    {
        projectile->HandleEvent(a_event);
    }
}

void World::ActiveProjectile(std::string a_tag, sf::Vector2f a_position, sf::Vector2f a_direction,
                             std::string a_tileMap, std::pair<int, int> a_tileIndex, int a_tileSize, float a_speed)
{
    Projectile* projectile = m_pool->GetProjectile();
    projectile->Init(a_tag, a_position, a_direction, a_tileMap, a_tileIndex, a_tileSize, a_speed);
    m_activeProjectiles.push_back(projectile);
}

void World::DisableProjectile(Projectile* a_projectile)
{
    std::vector<Projectile*>::iterator index = std::find(m_activeProjectiles.begin(), m_activeProjectiles.end(),a_projectile);
    if (index == m_activeProjectiles.end())
    {
        return;
    }
    m_activeProjectiles.erase(index);
    m_pool->InsertProjectile(a_projectile);
}

void World::RemoveAI(AICharacter* a_aiCharacter)
{
    m_aiSpawner->RemoveAi(a_aiCharacter);
}

void World::BlockPlayerInWorld()
{
    float posX = m_player.getPosition().x;
    float posY = m_player.getPosition().y;
    if (posX > 384 )
    {
        m_player.setPosition({384, posY});
    }
    if (posX < -384)
    {
        m_player.setPosition({-384, posY});
    }
    if (posY > 384 )
    {
        m_player.setPosition({posX, 384});
    }
    if (posY < -384)
    {
        m_player.setPosition({posX, -384});
    }
}


