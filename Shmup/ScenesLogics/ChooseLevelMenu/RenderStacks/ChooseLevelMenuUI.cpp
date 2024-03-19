#include "ChooseLevelMenuUI.h"

ChooseLevelMenuUI::ChooseLevelMenuUI() : m_levelButtons()
{
}

void ChooseLevelMenuUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.setView(m_view);
    for (auto button : m_levelButtons)
    {
        target.draw(*button);
    }
}

void ChooseLevelMenuUI::Load()
{
    m_view = sf::View({400, 400}, {800, 800});
    ChooseLevelButton* newLevelButton = new ChooseLevelButton(m_view, 0);
    m_levelButtons.push_back(newLevelButton);
}

void ChooseLevelMenuUI::Update(sf::Time a_deltaTime)
{
    for (auto levelButton : m_levelButtons)
    {
        levelButton->Update(a_deltaTime);
    }
}

void ChooseLevelMenuUI::Init()
{
    m_levelButtons[0]->Init();
    m_levelButtons[0]->setPosition(400,400);
    ARenderStack::Init();
}

void ChooseLevelMenuUI::HandleEvent(sf::Event a_event)
{
    ARenderStack::HandleEvent(a_event);
    for (auto levelButton : m_levelButtons)
    {
        levelButton->HandleEvent(a_event);
    }
}
