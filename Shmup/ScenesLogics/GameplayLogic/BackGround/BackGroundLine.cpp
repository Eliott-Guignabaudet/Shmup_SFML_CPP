#include "BackGroundLine.h"

#include <iostream>

#include "../../../Managers/RessourceManager.h"

void BackGroundLine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    for (sf::Sprite* sprite : m_sprites)
    {
        target.draw(*sprite, states);
    }
}

void BackGroundLine::Load()
{
    for (int i = 0; i < m_sprtitesRects.size(); ++i)
    {
        sf::Sprite* newSprite = new sf::Sprite();
        newSprite->setTexture(*RessourceManager::GetInstance()->GetTexture("Tiles"));
        newSprite->setTextureRect(m_sprtitesRects[i]);
        newSprite->setPosition({(static_cast<float>(i) * 16.f), 0.f});
        newSprite->setColor({192,192,192,255});
        m_sprites.push_back(newSprite);
    }
}

void BackGroundLine::Init()
{
}

void BackGroundLine::Update(sf::Time a_deltaTime)
{
    
}

void BackGroundLine::HandleEvent(sf::Event a_event)
{
}

BackGroundLine::BackGroundLine()
{
}

BackGroundLine::BackGroundLine(std::vector<sf::IntRect> a_rects) : m_sprtitesRects(a_rects)
{
}
