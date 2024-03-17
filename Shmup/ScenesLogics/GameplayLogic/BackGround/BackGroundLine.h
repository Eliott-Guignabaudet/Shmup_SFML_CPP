#pragma once
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

#include "../../AEntity.h"

class BackGroundLine : public AEntity
{
private:
    std::vector<sf::IntRect> m_sprtitesRects;
    std::vector<sf::Sprite*> m_sprites;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;

    BackGroundLine();
    BackGroundLine(std::vector<sf::IntRect>);
    
};
