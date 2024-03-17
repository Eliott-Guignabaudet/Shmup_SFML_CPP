#pragma once
#include "../Menu/AButton.h"

class MenuButton : public AButton
{
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    MenuButton(sf::View& a_view);
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;

private:
    sf::Text m_text;
    
    void OnClick() override;
    void OnMouseEnter() override;
    void OnMouseExit() override;
};