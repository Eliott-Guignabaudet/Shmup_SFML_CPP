#pragma once
#include "../StartGameButton.h"
#include "../../ARenderStack.h"

class MenuUI : public ARenderStack
{
private:
    StartGameButton m_startGameButton;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    MenuUI();
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;
};
