#include "StartGameButton.h"

#include "../../Managers/Manager.h"

StartGameButton::StartGameButton() : AButton()
{
}

void StartGameButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_bounds, states);
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
