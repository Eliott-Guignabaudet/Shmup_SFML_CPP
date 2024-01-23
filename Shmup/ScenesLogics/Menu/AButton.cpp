#include "AButton.h"

#include <iostream>

#include "../../Managers/Manager.h"

AButton::AButton(sf::View& a_view) : m_isMouseEnter(false), m_isMouseClicking(false), m_bounds({200, 50}), m_view(a_view)
{
}

void AButton::HandleEvent(sf::Event a_event)
{
    if (a_event.type == sf::Event::MouseMoved)
    {
        bool isMouseInBounds;
        
        //sf::FloatRect absoluteBoundsRect = getTransform().transformRect(m_bounds.getTransform().transformRect(m_bounds.getLocalBounds()));
        sf::FloatRect absoluteBoundsRect = getTransform().transformRect(m_bounds.getLocalBounds());
        sf::Vector2f mousePositionMapped = Manager::GetInstance()->GetMousePositionMapped(m_view);
        isMouseInBounds = absoluteBoundsRect.contains(mousePositionMapped);

        std::cout << "Mouse Mapped Position: " << mousePositionMapped.x << ", " << mousePositionMapped.y << std::endl;
        
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
