#pragma once
#include <SFML/Graphics.hpp>

class ARenderStack : public sf::Drawable
{
protected:
    sf::View m_view;
public:
    virtual void Load() = 0;
    virtual void Init() = 0;
    virtual void Update(sf::Time a_deltaTime) = 0;
    virtual void HandleEvent(sf::Event a_event);
};
