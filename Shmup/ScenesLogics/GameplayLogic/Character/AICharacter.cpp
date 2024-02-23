#define _USE_MATH_DEFINES
#include "AICharacter.h"

AICharacter::AICharacter()
{
}

AICharacter::AICharacter(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife):
    Character(a_position, a_direction, a_speed, a_maxLife)
{
    SetDirection(a_direction);
}

AICharacter::~AICharacter()
{
}


void AICharacter::Shoot()
{
    Character::Shoot();
}

void AICharacter::Load()
{
    Character::Load();
}

void AICharacter::Init()
{
    //setRotation(180);
    m_texturePlacement = sf::IntRect(32,0,32,32);
    m_sprite.setTextureRect(m_texturePlacement);
    Character::Init();
}

void AICharacter::Update(sf::Time a_deltaTime)
{
    Character::Update(a_deltaTime);
}

void AICharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Character::draw(target, states);
}

void AICharacter::HandleEvent(sf::Event a_event)
{
    Character::HandleEvent(a_event);
}

void AICharacter::SetDirection(sf::Vector2f a_direction)
{
    Character::SetDirection(a_direction);
    if (GetDirection() != sf::Vector2f(0,0))
    {
        setRotation((atan2(GetDirection().y, GetDirection().x)*180/static_cast<float>(M_PI))+90.f);
    }
    else
    {
        setRotation(0);
    }
}
