#include "Manager.h"

#include "../ScenesLogics/GameplayLogic/GameplayScene.h"


Manager* Manager::m_instance = nullptr;

Manager::Manager() :  m_window(sf::VideoMode(800,800), "Shmup")
{
    GameplayScene* gameplayScene = new GameplayScene();
    m_scenes.insert({"Gameplay", gameplayScene});
}

Manager::~Manager()
{
    for (std::pair<std::string, Scene*>  scene : m_scenes)
    {
        delete scene.second;
    }
}

Manager* Manager::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Manager();
    }
    return m_instance;
}


void Manager::Run()
{
    LoadScene("Gameplay");
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

void Manager::LoadScene(std::string a_sceneName)
{
    m_actualScene = m_scenes[a_sceneName];
    m_actualScene->Load();
}


void Manager::LoadScene(int a_index)
{
    auto it = m_scenes.begin();
    std::advance(it, a_index);
    m_actualScene = it->second;
    m_actualScene->Load();
}

void Manager::Init()
{
    m_actualScene->Init();
}

void Manager::Update(sf::Time a_deltaTime)
{
    m_actualScene->Update(a_deltaTime);
}

void Manager::Draw()
{
    m_window.clear(sf::Color::Black);
    m_window.draw(*m_actualScene);
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
        m_actualScene->HandleEvent(event);
    }
}




