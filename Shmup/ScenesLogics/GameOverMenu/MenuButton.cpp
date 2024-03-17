#include "MenuButton.h"

#include "../../Managers/Manager.h"
#include "../../Managers/RessourceManager.h"

MenuButton::MenuButton(sf::View& a_view) : AButton(a_view), m_text("Menu", *RessourceManager::GetInstance()->GetFont("Pixel"))
{
    m_text.setFillColor(sf::Color::Black);
    m_text.setCharacterSize(30);
    //m_text.setOrigin({m_text.getLocalBounds().getSize()/2.f});
    m_text.setPosition({(m_bounds.getLocalBounds().getSize()/2.f) - (m_text.getLocalBounds().getSize()/2.f) });
    
}

void MenuButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_bounds, states);
    target.draw(m_text, states);
}

void MenuButton::Load()
{
}

void MenuButton::Init()
{
    setOrigin(100,25);
}

void MenuButton::Update(sf::Time a_deltaTime)
{
}

void MenuButton::OnClick()
{
    Manager::GetInstance()->LoadScene("Menu");
}

void MenuButton::OnMouseEnter()
{
    m_bounds.setFillColor(sf::Color::Green);
}

void MenuButton::OnMouseExit()
{
    m_bounds.setFillColor(sf::Color::White);
}
