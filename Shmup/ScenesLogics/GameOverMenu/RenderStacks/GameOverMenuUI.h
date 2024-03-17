#pragma once
#include "../MenuButton.h"
#include "../../ARenderStack.h"
#include "../../Menu/QuitGameButton.h"

class GameOverMenuUI : public ARenderStack
{
private:
    QuitGameButton m_quitGameButton;
    sf::Text m_gameOverText;
    MenuButton m_menuButton;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    GameOverMenuUI();
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void HandleEvent(sf::Event a_event) override;
};
