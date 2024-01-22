#pragma once
#include "../../AEntity.h"

class Projectile:
    public AEntity
{
private:
    sf::Sprite m_sprite;
    sf::IntRect m_tileIndex;
    sf::Vector2f m_direction;
    std::string m_tag;
    float m_speed;
    sf::RectangleShape m_bounds;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    Projectile();
    void Load() override;
    void Init() override;
    void Init(std::string a_tag, sf::Vector2f a_position, sf::Vector2f a_direction, std::string a_tileMap,std::pair<int, int> a_tileIndex, int a_tileSize, float a_speed) ;
    void Reset();
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;
    sf::RectangleShape GetBounds();
    std::string GetTag();
};
