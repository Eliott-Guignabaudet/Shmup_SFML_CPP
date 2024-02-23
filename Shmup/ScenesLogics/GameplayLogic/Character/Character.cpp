#include "Character.h"

#include <iostream>

#include "../../../Managers/RessourceManager.h"

Character::Character() :
    m_speed(1),
    m_currentLife(1),
    m_maxLife(1),
    m_direction(sf::Vector2f(1,0))
{
}

Character::Character(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife) :
    m_speed(a_speed),
    m_currentLife(a_maxLife),
    m_maxLife(a_maxLife),
    m_direction(a_direction)
{
    SetDirection(a_direction);
    setOrigin(sf::Vector2f(16,16));
    setPosition(a_position);
    m_bounds.setRadius(10);

    // C'est bizarre quand même 
    m_bounds.setOrigin({-6,-6});
    
    m_bounds.setOutlineThickness(1.f);
    m_bounds.setOutlineColor(sf::Color::Green);
    m_bounds.setFillColor(sf::Color::Transparent);
}

void Character::Load()
{
    // m_sprite.setTexture(*RessourceManager::GetInstance()->GetTexture("Ships"));
    // m_sprite.setTextureRect({0,0,32,32});
}

void Character::Init()
{
    m_sprite.setTexture(*RessourceManager::GetInstance()->GetTexture("Ships"));
}

void Character::Update(sf::Time a_deltaTime)
{
    move(m_direction * m_speed * a_deltaTime.asSeconds());
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_sprite, states);


    // Marche Uniquement si le bound fait la même taille que le sprite
    //states.transform.combine(m_bounds.getTransform());
#ifdef _DEBUG
    target.draw(m_bounds, states);
#endif
    
}

void Character::Shoot()
{
    // ?
}

void Character::Die()
{
    m_sprite.setColor(sf::Color(0,0,0,0));
    m_bounds.setOutlineColor(sf::Color::Transparent);
}

void Character::SetDirection(sf::Vector2f a_direction)
{
    m_direction = a_direction;
    if (m_direction != sf::Vector2f(0,0))
    {
        float magnitude = ((m_direction.x * m_direction.x) + (m_direction.y * m_direction.y));
        m_direction = m_direction/magnitude; 
    }

}

void Character::TakeDamage()
{
    m_currentLife--;
    if (m_currentLife <= 0)
    {
        Die();
    }
}

sf::CircleShape Character::GetBounds()
{
    //m_bounds.setOrigin(sf::Vector2f( (m_bounds.getRadius() - getOrigin().x)/2,(m_bounds.getRadius() - getOrigin().y)/2));

    return m_bounds;
}

bool Character::GetIsDead()
{
    return m_currentLife <=0;
}

void Character::HandleEvent(sf::Event a_event)
{
    
}


sf::Vector2f Character::GetDirection()
{
    return m_direction;
}





