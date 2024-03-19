#include "ChooseLevelMenuUI.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

#include "../../../Managers/DestructionManager.h"

ChooseLevelMenuUI::ChooseLevelMenuUI() : m_levelButtons()
{
}

ChooseLevelMenuUI::~ChooseLevelMenuUI()
{
    for (auto button : m_levelButtons)
    {
        DestructionManager::GetInstance()->AddPtrToDestroy(button);
    }
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
    std::ifstream  ifs("./Data/LevelDatas.json");
    if (ifs)
    {
        nlohmann::json jsonData = nlohmann::json::parse(ifs);
        for (int i = 0; i < jsonData["Levels"].size(); ++i)
        {
            ChooseLevelButton* newLevelButton = new ChooseLevelButton(m_view, i, jsonData["Levels"][i]);
            m_levelButtons.push_back(newLevelButton);
        }
    }
    
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
    for (int i = 0; i < m_levelButtons.size(); ++i)
    {
        m_levelButtons[i]->Init();
        m_levelButtons[i]->setPosition(400,200 + 100*(i));
    }
    
    
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
