#include "BackGround.h"

#include "../../../Managers/RessourceManager.h"

BackGround::BackGround() : m_spriteColor(128,128,128,255)
{
    for (int i = 0; i < 3; ++i)
    {
        sf::Sprite* sprite = new sf::Sprite();
        m_sprites.push_back(sprite);
    }

}

BackGround::~BackGround()
{
    for (sf::Sprite* sprite : m_sprites)
    {
        delete sprite;
    }
}

void BackGround::Load()
{

}

void BackGround::Init()
{
    m_textureRect = sf::IntRect(16*1, 16*4, 16, 16);
    for (int i = 0; i < m_sprites.size(); ++i)
    {
        m_sprites[i]->setTexture(*RessourceManager::GetInstance()->GetTexture("Tiles"));
        m_sprites[i]->setTextureRect(m_textureRect);
        m_sprites[i]->setPosition(sf::Vector2f(0, -i * 16));
        m_sprites[i]->setColor(m_spriteColor);
    }
    m_view = sf::View(sf::FloatRect(0,0, 16,16));
}

void BackGround::Update(sf::Time a_deltaTime)
{
    for (sf::Sprite* sprite : m_sprites)
    {
        sprite->move(sf::Vector2f(0, 5 * a_deltaTime.asSeconds()));
        if (sprite->getPosition().y > 16)
        {
            sprite->move(sf::Vector2f(0, -32));
        }
    }
}

void BackGround::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.setView(m_view);
    for (sf::Sprite* sprite : m_sprites)
    {
        target.draw(*sprite);
    }
}

void BackGround::HandleEvent(sf::Event a_event)
{
}
