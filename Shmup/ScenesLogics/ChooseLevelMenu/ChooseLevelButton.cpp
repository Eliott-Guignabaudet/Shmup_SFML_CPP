#include "ChooseLevelButton.h"

#include "../../Managers/Manager.h"
#include "../../Managers/RessourceManager.h"

ChooseLevelButton::ChooseLevelButton(sf::View& a_view):
    AButton(a_view),
    m_levelIndex(0),
    m_text("Level " + m_levelIndex, *RessourceManager::GetInstance()->GetFont("Pixel"))
{
    m_text.setFillColor(sf::Color::Black);
    m_text.setCharacterSize(30);
    //m_text.setOrigin({m_text.getLocalBounds().getSize()/2.f});
    m_text.setPosition({(m_bounds.getLocalBounds().getSize()/2.f) - (m_text.getLocalBounds().getSize()/2.f) });
}

ChooseLevelButton::ChooseLevelButton(sf::View& a_view, int a_levelIndex) :
    AButton(a_view),
    m_levelIndex(a_levelIndex),
    m_text("Level " + m_levelIndex, *RessourceManager::GetInstance()->GetFont("Pixel"))
{
    m_text.setFillColor(sf::Color::Black);
    m_text.setCharacterSize(30);
    //m_text.setOrigin({m_text.getLocalBounds().getSize()/2.f});
    m_text.setPosition({(m_bounds.getLocalBounds().getSize()/2.f) - (m_text.getLocalBounds().getSize()/2.f) });
}

void ChooseLevelButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    target.draw(m_bounds, states);
    target.draw(m_text, states);
}

void ChooseLevelButton::Load()
{
}

void ChooseLevelButton::Init()
{
    setOrigin(100,25);
}

void ChooseLevelButton::Update(sf::Time a_deltaTime)
{
}

void ChooseLevelButton::OnClick()
{
    Manager::GetInstance()->LoadScene("Gameplay");
}

void ChooseLevelButton::OnMouseEnter()
{
    m_bounds.setFillColor(sf::Color::Green);
}

void ChooseLevelButton::OnMouseExit()
{
    m_bounds.setFillColor(sf::Color::White);
}
