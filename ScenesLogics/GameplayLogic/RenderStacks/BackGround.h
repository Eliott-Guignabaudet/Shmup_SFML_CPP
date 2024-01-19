#pragma once
#include "../../ARenderStack.h"

class BackGround : public ARenderStack
{
private:
    sf::IntRect m_textureRect;
    std::vector<sf::Sprite*> m_sprites;
    sf::Color m_spriteColor;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    BackGround();
    ~BackGround() override;
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;
};
