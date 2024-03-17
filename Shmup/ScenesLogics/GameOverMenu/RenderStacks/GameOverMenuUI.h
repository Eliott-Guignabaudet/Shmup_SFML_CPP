#pragma once
#include "../../ARenderStack.h"
#include "../../Menu/QuitGameButton.h"

class GameOverMenuUI : public ARenderStack
{
private:
    QuitGameButton m_quitGameButton;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    GameOverMenuUI();
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;
};