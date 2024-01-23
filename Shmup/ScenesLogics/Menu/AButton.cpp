#include "AButton.h"

#include <iostream>

AButton::AButton() : m_isMouseEnter(false), m_isMouseClicking(false), m_bounds({200, 50})
{
}

void AButton::HandleEvent(sf::Event a_event)
{
    if (a_event.type == sf::Event::MouseMoved)
    {
        bool isMouseInBounds;
        
        sf::FloatRect absoluteBoundsRect = getTransform().transformRect(m_bounds.getTransform().transformRect(m_bounds.getGlobalBounds()));
        isMouseInBounds = absoluteBoundsRect.contains({static_cast<float>(a_event.mouseMove.x), static_cast<float>(a_event.mouseMove.y)});
        
        if (isMouseInBounds && !m_isMouseEnter)
        {
            m_isMouseEnter = true;
            OnMouseEnter();
        }
        else if(!isMouseInBounds && m_isMouseEnter)
        {
            m_isMouseEnter = false;
            m_isMouseClicking = false;
            OnMouseExit();
        }
    }
    if (a_event.type == sf::Event::MouseButtonPressed)
    {
        if (m_isMouseEnter)
        {
            m_isMouseClicking = true;
        }
    }
    if (a_event.type == sf::Event::MouseButtonReleased)
    {
        if (m_isMouseClicking)
        {
            OnClick();
        }
        m_isMouseClicking = false;
    }
}
