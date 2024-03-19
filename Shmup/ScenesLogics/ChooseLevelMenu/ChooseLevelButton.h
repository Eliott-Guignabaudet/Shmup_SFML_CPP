#pragma once
#include "../Menu/AButton.h"

class ChooseLevelButton : public AButton
{
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    ChooseLevelButton(sf::View& a_view);
    ChooseLevelButton(sf::View& a_view,int a_levelIndex);
private:
    int m_levelIndex;
    sf::Text m_text;

    void OnClick() override;
    void OnMouseEnter() override;
    void OnMouseExit() override;
};
