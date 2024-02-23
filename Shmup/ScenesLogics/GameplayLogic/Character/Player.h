#pragma once
#include <functional>

#include "Character.h"

class Player : public Character
{
private:
    std::pair<bool, bool> m_xAxis;
    std::pair<bool, bool> m_yAxis;
    std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> m_shootCallBack;
    float m_fireCoolDown;
    float m_timeSinceLastShot;
    bool m_isShooting;
    float m_invicibleTime;
    int m_score;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void Shoot() override;

public:
    Player();
    Player(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife, std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> a_shootCallBack);
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;
    void TakeDamage() override;
    void AddScore(int a_score);
};

