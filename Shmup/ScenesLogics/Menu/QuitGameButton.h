#pragma once
#include "AButton.h"

class QuitGameButton : public  AButton
{
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    QuitGameButton(sf::View& a_view);
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;

private:
    sf::Text m_text;
    
    void OnClick() override;
    void OnMouseEnter() override;
    void OnMouseExit() override;
};
