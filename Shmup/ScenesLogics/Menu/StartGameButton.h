#pragma once
#include "AButton.h"

class StartGameButton : public AButton
{
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    StartGameButton();
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;

private:
    void OnClick() override;
    void OnMouseEnter() override;
    void OnMouseExit() override;
};
