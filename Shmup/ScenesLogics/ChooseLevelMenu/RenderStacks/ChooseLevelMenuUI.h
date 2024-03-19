#pragma once
#include "../ChooseLevelButton.h"
#include "../../ARenderStack.h"

class ChooseLevelMenuUI : public ARenderStack
{
private:
    std::vector<ChooseLevelButton*> m_levelButtons;
    
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    ChooseLevelMenuUI();
    void Load() override;
    void Update(sf::Time a_deltaTime) override;
    void Init() override;
    void HandleEvent(sf::Event a_event) override;
};
