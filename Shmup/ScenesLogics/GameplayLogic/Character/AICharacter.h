#pragma once
#include <functional>

#include "Character.h"

class AICharacter : public Character
{
private:
    std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> m_shootCallBack;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void Shoot() override;

public:
    AICharacter();
    AICharacter(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife);
    ~AICharacter() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;
    void Load() override;
};
