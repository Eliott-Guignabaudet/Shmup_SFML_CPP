#include "GameOverMenuUI.h"

#include "../../../Managers/RessourceManager.h"

GameOverMenuUI::GameOverMenuUI() : m_quitGameButton(m_view), m_menuButton(m_view)
{
}

void GameOverMenuUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.setView(m_view);
    target.draw(m_menuButton);
    target.draw(m_quitGameButton);
    target.draw(m_gameOverText);
}

void GameOverMenuUI::Load()
{
    m_view = sf::View({400, 400}, {800, 800});
    m_gameOverText.setString("Game Over!");
    m_gameOverText.setFont(*RessourceManager::GetInstance()->GetFont("Pixel"));
    m_gameOverText.setPosition({275,200});
    m_menuButton.Load();
    m_quitGameButton.Load();
}

void GameOverMenuUI::Init()
{
    m_menuButton.Init();
    m_menuButton.setPosition(400,400);
    m_quitGameButton.Init();
    m_quitGameButton.setPosition(400,600);
    ARenderStack::Init();
}

void GameOverMenuUI::Update(sf::Time a_deltaTime)
{
    m_menuButton.Update(a_deltaTime);
    m_quitGameButton.Update(a_deltaTime);
}

void GameOverMenuUI::HandleEvent(sf::Event a_event)
{
    ARenderStack::HandleEvent(a_event);
    m_menuButton.HandleEvent(a_event);
    m_quitGameButton.HandleEvent(a_event);
}