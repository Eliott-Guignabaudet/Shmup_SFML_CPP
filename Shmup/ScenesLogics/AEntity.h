#pragma once
#include <SFML/Graphics.hpp>


class AEntity:
    public sf::Transformable,
    public sf::Drawable
{
public:
    virtual void Load() = 0;
    virtual void Init() = 0;
    virtual void Update(sf::Time a_deltaTime) = 0;
    virtual void HandleEvent(sf::Event a_event) = 0;
};


