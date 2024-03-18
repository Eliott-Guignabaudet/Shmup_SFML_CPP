#include "AIShootVertical.h"


AIShootVertical::AIShootVertical(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife, float a_timeBetweenShoot, std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> a_shootCallBack) :
    AICharacter(a_position, a_direction, a_speed, a_maxLife),
    m_timeBetweenShoot(a_timeBetweenShoot),
    m_shootCallBack(a_shootCallBack),
    m_timeElapsedSinceLastShoot(0)
{
    
}


void AIShootVertical::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    AICharacter::draw(target, states);
}

void AIShootVertical::Shoot()
{
    AICharacter::Shoot();
    m_shootCallBack("AI", getPosition(), sf::Vector2f(0,1), "Tiles", {0,0}, 16, 500);
}

void AIShootVertical::Init()
{
    AICharacter::Init();
}

void AIShootVertical::Update(sf::Time a_deltaTime)
{
    AICharacter::Update(a_deltaTime);
    m_timeElapsedSinceLastShoot += a_deltaTime.asSeconds();
    if (m_timeElapsedSinceLastShoot >= m_timeBetweenShoot)
    {
        Shoot();
        m_timeElapsedSinceLastShoot = 0;
    }
}

void AIShootVertical::Load()
{
    AICharacter::Load();
}
