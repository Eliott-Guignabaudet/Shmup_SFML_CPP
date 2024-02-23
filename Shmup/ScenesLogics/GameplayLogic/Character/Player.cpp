#include "Player.h"

#include "../../../Managers/Manager.h"


Player::Player() :
    Character(),
    m_xAxis(false, false),
    m_yAxis(false, false),
    m_invicibleTime(1.f)
{
}

Player::Player(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife, std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> a_shootCallBack) :
    Character(a_position, a_direction, a_speed, a_maxLife),
    m_xAxis(false, false),
    m_yAxis(false, false),
    m_shootCallBack(a_shootCallBack),
    m_fireCoolDown(0.1f),
    m_timeSinceLastShot(0),
    m_isShooting(false),
    m_invicibleTime(1.f)
{
    
}

void Player::Shoot()
{
    Character::Shoot();
    m_shootCallBack("Player", getPosition(), sf::Vector2f(0,-1), "Tiles", {0,0}, 16, 500);
}

void Player::Init()
{
    Character::Init();
    m_texturePlacement = sf::IntRect(0,0,32,32);
    m_sprite.setTextureRect(m_texturePlacement);
}

void Player::Update(sf::Time a_deltaTime)
{
    sf::Vector2f newDirection(0,0);
    if (m_xAxis.first) newDirection.x +=1;
    if (m_xAxis.second) newDirection.x -=1;
    if (m_yAxis.first) newDirection.y -=1;
    if (m_yAxis.second) newDirection.y +=1;
    SetDirection(newDirection);
    m_timeSinceLastShot += a_deltaTime.asSeconds();
    if (m_timeSinceLastShot >= m_fireCoolDown && m_isShooting)
    {
        m_timeSinceLastShot =0;
        Shoot();
    }
    //rotate(180* a_deltaTime.asSeconds());
    Character::Update(a_deltaTime);
    m_invicibleTime += a_deltaTime.asSeconds();
}

void Player::TakeDamage()
{
    if (m_invicibleTime < 1.f)
    {
        return;
    }
    Character::TakeDamage();
    m_invicibleTime = 0.f;
    if (GetIsDead())
    {
        Manager::GetInstance()->LoadScene("Menu");
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Character::draw(target, states);
}


void Player::HandleEvent(sf::Event a_event)
{
    Character::HandleEvent(a_event);
    if (a_event.type == sf::Event::KeyPressed)
    {
        switch (a_event.key.scancode)
        {
        case sf::Keyboard::Scan::Up:
            m_yAxis.first = true;
            break;
        case sf::Keyboard::Scan::Down:
            m_yAxis.second = true;
            break;
        case sf::Keyboard::Scan::Right:
            m_xAxis.first = true;
            break;
        case sf::Keyboard::Scan::Left:
            m_xAxis.second = true;
            break;
        case sf::Keyboard::Scan::Space:
            m_isShooting = true;
            break;
        case sf::Keyboard::Scan::Enter:
            setPosition({0,0});
            break;
        }
    }
    if (a_event.type == sf::Event::KeyReleased)
    {
        switch (a_event.key.scancode)
        {
        case sf::Keyboard::Scan::Up:
            m_yAxis.first = false;
            break;
        case sf::Keyboard::Scan::Down:
            m_yAxis.second = false;
            break;
        case sf::Keyboard::Scan::Right:
            m_xAxis.first = false;
            break;
        case sf::Keyboard::Scan::Left:
            m_xAxis.second = false;
            break;
        case sf::Keyboard::Scan::Space:
            m_isShooting = false;
            break;
        }
    }
}
