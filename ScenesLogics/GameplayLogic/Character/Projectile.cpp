#include "Projectile.h"

#include "../../../Managers/RessourceManager.h"

Projectile::Projectile() : m_direction(sf::Vector2f(0,0)), m_speed(0)
{
}

void Projectile::Init()
{
}

void Projectile::Load()
{
}

std::string Projectile::GetTag()
{
    return m_tag;
}

void Projectile::Init(std::string a_tag,sf::Vector2f a_position, sf::Vector2f a_direction, std::string a_tileMap,
                      std::pair<int, int> a_tileIndex, int a_tileSize, float a_speed)
{
    m_tag = a_tag;
    setPosition(a_position);
    setOrigin(a_tileSize/2, a_tileSize/2);
    m_direction = a_direction;
    m_sprite.setTexture(*RessourceManager::GetInstance()->GetTexture(a_tileMap));
    m_tileIndex = sf::IntRect(a_tileIndex.first * a_tileSize, a_tileIndex.second * a_tileSize, a_tileSize, a_tileSize);
    m_sprite.setTextureRect(m_tileIndex);
    m_speed = a_speed;
    m_bounds = sf::RectangleShape({8,16});
    m_bounds.setOrigin({-4,0});
    m_bounds.setFillColor(sf::Color::Transparent);
    m_bounds.setOutlineColor(sf::Color::Green);
    m_bounds.setOutlineThickness(1.f);
}

void Projectile::Update(sf::Time a_deltaTime)
{
    move(m_direction * m_speed * a_deltaTime.asSeconds());
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_sprite, states);
    target.draw(m_bounds,states);
}

void Projectile::Reset()
{
    setPosition(sf::Vector2f(0,0));
    m_direction = sf::Vector2f(0,0);
    m_tileIndex = sf::IntRect(0,0,0,0);
    m_speed = 0;
    m_tag = "";
}

sf::RectangleShape Projectile::GetBounds()
{
    return m_bounds;
}

void Projectile::HandleEvent(sf::Event a_event)
{
}

