#include "MenuUI.h"


MenuUI::MenuUI() : m_startGameButton()
{
}

void MenuUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.setView(m_view);
    target.draw(m_startGameButton);
}

void MenuUI::Load()
{
    m_view = sf::View({400, 400}, {800, 800});
    m_startGameButton.Load();
}

void MenuUI::Init()
{
    m_startGameButton.Init();
    m_startGameButton.setPosition(400,200);
}

void MenuUI::Update(sf::Time a_deltaTime)
{
    m_startGameButton.Update(a_deltaTime);
}

void MenuUI::HandleEvent(sf::Event a_event)
{
    ARenderStack::HandleEvent(a_event);

    m_startGameButton.HandleEvent(a_event);
}
