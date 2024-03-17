#include "World.h"

#include <functional>
#include <iostream>
#include <Windows.h>
#include <math.h>

#include "../Character/AIShootVertical.h"
#include "../Character/AiSuicideCharacter.h"
#include "../Character/Player.h"

World::World() : m_activeProjectiles()
{

}

World::~World()
{
    delete m_pool;
    for (AICharacter* aiCharacter : m_aiCharacters)
    {
        delete aiCharacter;
    }
}


void World::Load()
{
    using namespace std::placeholders;
    m_pool = new ProjectilePool(10);
    auto function = std::bind(&World::ActiveProjectile, this, _1, _2, _3, _4, _5, _6, _7);
    Player player(sf::Vector2f(0, 0), sf::Vector2f(1, 5), 250, 2, function);
    m_player = player;

    AICharacter* aiCharacter = new AICharacter(sf::Vector2f(0, -200), sf::Vector2f(0, 0), 50, 10);
    m_aiCharacters.push_back(aiCharacter);
    AiSuicideCharacter* suicideCharacter = new AiSuicideCharacter(sf::Vector2f(-100, -200),
                                                                  player.getPosition() - sf::Vector2f(-100, -200),
                                                                  20000, 1);
    m_aiCharacters.push_back(suicideCharacter);

    AIShootVertical* aiShootVertical = new AIShootVertical(sf::Vector2f(100, -200), {-1,1}, 200, 5, 0.5f, function);
    m_aiCharacters.push_back(aiShootVertical);
    m_view.reset(sf::FloatRect(-400, -400, 800, 800));
    m_player.Load();
}

void World::Init()
{
    m_player.Init();
    for (AICharacter* character : m_aiCharacters)
    {
        character->Init();
    }
    ARenderStack::Init();
}

void World::Update(sf::Time a_deltaTime)
{
    m_player.Update(a_deltaTime);
    for (AICharacter* character : m_aiCharacters)
    {
        character->Update(a_deltaTime);

        // sf::Vector2f absoluteAiCharacterPointPosition = character->getTransform().transformPoint(
        //     character->GetBounds().getTransform().transformPoint(
        //         character->GetBounds().getPosition()
        //     )
        // );
        // sf::Vector2f absolutePlayerPosition = m_player.getTransform().transformPoint(
        //     m_player.GetBounds().getTransform().transformPoint(
        //         m_player.GetBounds().getPosition()
        //     ));
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
                delete character;
                std::vector<AICharacter*>::iterator index = std::find(
                    m_aiCharacters.begin(), m_aiCharacters.end(), character);
                m_aiCharacters.erase(index);
                m_player.AddScore(100);
            }
            m_player.TakeDamage();
            std::cout << "Collision!" << std::endl;
        }
    }
    for (Projectile* projectile : m_activeProjectiles)
    {
        projectile->Update(a_deltaTime);
        CheckProjectileCollisions(projectile);
    }
}

void World::CheckProjectileCollisions(Projectile* a_projectile)
{
    if (a_projectile->GetTag() == "Player")
    {
        for (AICharacter* aiCharacter : m_aiCharacters)
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
                            m_aiCharacters.begin(), m_aiCharacters.end(), aiCharacter);
                        m_aiCharacters.erase(index);
                        m_player.AddScore(100);
                    }
                    DisableProjectile(a_projectile);
                    break;
                }
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
    for (AICharacter* character : m_aiCharacters)
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
    Projectile* projectile = a_projectile;
    std::vector<Projectile*>::iterator index = std::find(m_activeProjectiles.begin(), m_activeProjectiles.end(),
                                                         a_projectile);
    m_activeProjectiles.erase(index);
    m_pool->InsertProjectile(projectile);
}
