#include "ARenderStack.h"

#include "../Managers/Manager.h"

void ARenderStack::Init()
{
    float ratio = static_cast<float>(Manager::GetInstance()->GetWindowSize().x)/static_cast<float>(Manager::GetInstance()->GetWindowSize().y);
    m_view.setSize(m_view.getSize().y * ratio, m_view.getSize().y);
}

void ARenderStack::HandleEvent(sf::Event a_event)
{
    if (a_event.type == sf::Event::Resized)
    {
        float ratio = static_cast<float>(a_event.size.width)/static_cast<float>(a_event.size.height);
        m_view.setSize(m_view.getSize().y * ratio, m_view.getSize().y);
    }
}
