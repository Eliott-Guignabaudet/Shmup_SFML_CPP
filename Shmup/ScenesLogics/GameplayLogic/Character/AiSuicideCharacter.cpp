#include "AiSuicideCharacter.h"

void AiSuicideCharacter::Die()
{
    AICharacter::Die();
}

void AiSuicideCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    AICharacter::draw(target, states);
}

AiSuicideCharacter::AiSuicideCharacter(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed,
    float a_maxLife) : AICharacter(a_position, a_direction, a_speed, a_maxLife)
{
}

void AiSuicideCharacter::Load()
{
    AICharacter::Load();
}

void AiSuicideCharacter::Init()
{
    AICharacter::Init();
}

void AiSuicideCharacter::Update(sf::Time a_deltaTime)
{
    AICharacter::Update(a_deltaTime);
}

void AiSuicideCharacter::TakeDamage()
{
    AICharacter::TakeDamage();
}
