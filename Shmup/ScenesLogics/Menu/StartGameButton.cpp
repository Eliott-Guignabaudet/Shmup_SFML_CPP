#include "StartGameButton.h"

#include "../../Managers/Manager.h"
#include "../../Managers/RessourceManager.h"

StartGameButton::StartGameButton(sf::View& a_view) : AButton(a_view), m_text("Start", *RessourceManager::GetInstance()->GetFont("Pixel"))
{
    m_text.setFillColor(sf::Color::Black);
    m_text.setCharacterSize(30);
    //m_text.setOrigin({m_text.getLocalBounds().getSize()/2.f});
    m_text.setPosition({(m_bounds.getLocalBounds().getSize()/2.f) - (m_text.getLocalBounds().getSize()/2.f) });
    
}

void StartGameButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_bounds, states);
    target.draw(m_text, states);
}

void StartGameButton::Load()
{
}

void StartGameButton::Init()
{
    setOrigin(100,25);
}

void StartGameButton::Update(sf::Time a_deltaTime)
{
}

void StartGameButton::OnClick()
{
    Manager::GetInstance()->LoadScene("Gameplay");
}

void StartGameButton::OnMouseEnter()
{
    m_bounds.setFillColor(sf::Color::Green);
}

void StartGameButton::OnMouseExit()
{
    m_bounds.setFillColor(sf::Color::White);
}
