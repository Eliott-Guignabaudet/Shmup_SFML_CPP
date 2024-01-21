#pragma once
#include "../../ARenderStack.h"

class UI : public ARenderStack
{
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;
};
