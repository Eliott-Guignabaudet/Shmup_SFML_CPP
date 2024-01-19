#pragma once
#include "../AEntity.h"

class Character : public AEntity
{
private:
    float m_speed;
    float m_currentLife;
    float m_maxLife;
    sf::Vector2f m_direction;
    sf::CircleShape m_bounds;

    
protected:
    sf::Sprite m_sprite;
    sf::IntRect m_texturePlacement;
    // Shoot projectile
    virtual void Shoot();
    
    // Die if Current life equal 0
    virtual void Die();
    
    void SetDirection(sf::Vector2f a_direction);
    
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    Character();
    Character(sf::Vector2f a_position, sf::Vector2f a_direction, float a_speed, float a_maxLife);
    virtual void Load() override;
    virtual void Init() override;
    virtual void Update(sf::Time a_deltaTime) override;
    virtual void HandleEvent(sf::Event a_event) override;
    virtual void TakeDamage();
    sf::CircleShape GetBounds();
    bool GetIsDead();
    
};
