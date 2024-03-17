#include "GameOverMenuUI.h"

GameOverMenuUI::GameOverMenuUI() : m_quitGameButton(m_view)
{
}

void GameOverMenuUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.setView(m_view);
    //target.draw(m_startGameButton);
    target.draw(m_quitGameButton);
}

void GameOverMenuUI::Load()
{
    m_view = sf::View({400, 400}, {800, 800});
    //m_startGameButton.Load();
    m_quitGameButton.Load();
}

void GameOverMenuUI::Init()
{
    //m_startGameButton.Init();
    //m_startGameButton.setPosition(400,200);
    m_quitGameButton.Init();
    m_quitGameButton.setPosition(400,400);
    ARenderStack::Init();
}

void GameOverMenuUI::Update(sf::Time a_deltaTime)
{
    //m_startGameButton.Update(a_deltaTime);
    m_quitGameButton.Update(a_deltaTime);
}

void GameOverMenuUI::HandleEvent(sf::Event a_event)
{
    ARenderStack::HandleEvent(a_event);
    //m_startGameButton.HandleEvent(a_event);
    m_quitGameButton.HandleEvent(a_event);
}