#include "QuitGameButton.h"
#include "../../Managers/Manager.h"
#include "../../Managers/RessourceManager.h"

QuitGameButton::QuitGameButton(sf::View& a_view) : AButton(a_view), m_text("Quit", *RessourceManager::GetInstance()->GetFont("Pixel"))
{
    m_text.setFillColor(sf::Color::Black);
    m_text.setCharacterSize(30);
    //m_text.setOrigin({m_text.getLocalBounds().getSize()/2.f});
    m_text.setPosition({(m_bounds.getLocalBounds().getSize()/2.f) - (m_text.getLocalBounds().getSize()/2.f) });
    
}

void QuitGameButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_bounds, states);
    target.draw(m_text, states);
}

void QuitGameButton::Load()
{
}

void QuitGameButton::Init()
{
    setOrigin(100,25);
}

void QuitGameButton::Update(sf::Time a_deltaTime)
{
}

void QuitGameButton::OnClick()
{
    Manager::GetInstance()->GetWindow().close();
}

void QuitGameButton::OnMouseEnter()
{
    m_bounds.setFillColor(sf::Color::Red);
}

void QuitGameButton::OnMouseExit()
{
    m_bounds.setFillColor(sf::Color::White);
}