#include "BackGround.h"

#include <iostream>
#include <noise/noise.h>
#include <noise/noiseutils.h>
#include "../../../Managers/RessourceManager.h"

using namespace noise;
BackGround::BackGround() : m_spriteColor(128,128,128,255)
{
    // for (int i = 0; i < 3; ++i)
    // {
    //     sf::Sprite* sprite = new sf::Sprite();
    //     m_sprites.push_back(sprite);
    // }
    
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
    /*for (int i = 0; i < 51; ++i)
    {
        BackGroundLine* newLine = new BackGroundLine({
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*3, 16*4, 16, 16},
            {16*6, 16*3, 16, 16},
            {16*6, 16*3, 16, 16},
            {16*6, 16*3, 16, 16},
            {16*6, 16*3, 16, 16},
            {16*1, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
            {16*2, 16*4, 16, 16},
        });
        newLine->Load();
        newLine->setPosition({0, (static_cast<float>(i) * 16.f) - 16});
        m_lines.push_back(newLine);
    }*/
    
    module::Perlin myModule;
    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderPlane heightMapBuilder;
    heightMapBuilder.SetSourceModule (myModule);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize(51,51);
    heightMapBuilder.SetBounds(2.0, 6.0, 0.9, 4.9);
    heightMapBuilder.Build ();

    for (int i = 0; i < heightMap.GetHeight(); ++i)
    {
        std::vector<sf::IntRect> newLineRects = std::vector<sf::IntRect>(); 
        for (int j = 0; j < heightMap.GetWidth(); ++j)
        {
            
            if (heightMap.GetValue(i,j) < -0.5)
            {
                newLineRects.push_back({16 * 6,16*3,16,16});
            }
            else
            {
                newLineRects.push_back({16 * 2,16*4,16,16});
            }
        }
        BackGroundLine* newLine = new BackGroundLine(newLineRects);
        newLine->Load();
        newLine->setPosition({0, (static_cast<float>(i) * 16.f) - 16});
        m_lines.push_back(newLine);
    }
}

void BackGround::Init()
{
    // m_textureRect = sf::IntRect(16*1, 16*4, 16, 16);
    // for (int i = 0; i < m_sprites.size(); ++i)
    // {
    //     m_sprites[i]->setTexture(*RessourceManager::GetInstance()->GetTexture("Tiles"));
    //     m_sprites[i]->setTextureRect(m_textureRect);
    //     m_sprites[i]->setPosition(sf::Vector2f(0, static_cast<float>(-i * 16)));
    //     m_sprites[i]->setColor(m_spriteColor);
    // }
    //m_view = sf::View(sf::FloatRect(0,0, 16,16));
    m_view.reset(sf::FloatRect(0, 0, 800, 800));
    for (BackGroundLine* line : m_lines)
    {
        line->Init();
    }
    ARenderStack::Init();
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
    
    for (BackGroundLine* line : m_lines)
    {
        line->move(sf::Vector2f(0, 100 * a_deltaTime.asSeconds()));
        if (line->getPosition().y>800)
        {
            line->move({0,-816});
        }
        line->Update(a_deltaTime);
    }
}

void BackGround::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.setView(m_view);
    for (sf::Sprite* sprite : m_sprites)
    {
        target.draw(*sprite);
    }
    for (BackGroundLine* line : m_lines)
    {
        target.draw(*line);
    }
}

void BackGround::HandleEvent(sf::Event a_event)
{
    ARenderStack::HandleEvent(a_event);
}
