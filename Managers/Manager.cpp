#include "Manager.h"

#include "../ScenesLogics/GameplayLogic/GameplayScene.h"

Manager::Manager() : m_actualSceneIndex(0), m_window(sf::VideoMode(800,800), "Shmup")
{
    GameplayScene* gameplayScene = new GameplayScene();
    m_scenes.push_back(gameplayScene);
}

Manager::~Manager()
{
    for (Scene* scene : m_scenes)
    {
        delete scene;
    }
}

void Manager::Run()
{
    LoadScene(0);
    Init();
    m_window.setFramerateLimit(144);
    while(m_window.isOpen())
    {
        HandleEvent();

        sf::Time deltaTime = m_clock.restart();
        Update(deltaTime);
        Draw();
        
    }
}

void Manager::LoadScene(int a_index)
{
    m_scenes[a_index]->Load();
    m_actualSceneIndex = a_index;
}

void Manager::Init()
{
    m_scenes[m_actualSceneIndex]->Init();
}

void Manager::Update(sf::Time a_deltaTime)
{
    m_scenes[m_actualSceneIndex]->Update(a_deltaTime);
}

void Manager::Draw()
{
    m_window.clear(sf::Color::Black);
    m_window.draw(*m_scenes[m_actualSceneIndex]);
    m_window.display();
}


void Manager::HandleEvent()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        m_scenes[m_actualSceneIndex]->HandleEvent(event);
    }
}




