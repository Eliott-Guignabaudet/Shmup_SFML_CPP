#pragma once
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

#include "ARenderStack.h"

class Scene : public sf::Drawable
{

protected:
    std::vector<ARenderStack*> m_renderStacks;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    Scene();
    ~Scene() override;
    virtual void Load();
    virtual void Unload();
    virtual void Init();
    virtual void Update(sf::Time a_deltaTime);
    virtual void HandleEvent(sf::Event a_event);
    
};
