#pragma once
#include "../AEntity.h"

class AButton : public AEntity
{
private:
    bool m_isMouseEnter;
    bool m_isMouseClicking;
    virtual void OnClick() = 0;
    virtual void OnMouseEnter() = 0;
    virtual void OnMouseExit() = 0;

    sf::View& m_view;
protected:
    sf::RectangleShape m_bounds;
    
public:
    AButton(sf::View& a_view);
    void HandleEvent(sf::Event a_event) override;
};
