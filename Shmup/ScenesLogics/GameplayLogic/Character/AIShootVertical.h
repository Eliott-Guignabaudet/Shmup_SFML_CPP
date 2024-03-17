#pragma once
#include "AICharacter.h"

class AIShootVertical : public AICharacter
{
private:
    float m_timeElapsedSinceLastShoot;
    float m_timeBetweenShoot;
    std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> m_shootCallBack;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void Shoot() override;

public:
    AIShootVertical(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife, float a_timeBetweenShoot, std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> a_shootCallBack);
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void Load() override;
};
