#pragma once
#include "AICharacter.h"

class AiSuicideCharacter : public AICharacter
{
protected:
    void Die() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    AiSuicideCharacter(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife);
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void TakeDamage() override;
    
};
