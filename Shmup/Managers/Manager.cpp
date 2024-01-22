#include "Manager.h"

#include "../ScenesLogics/GameplayLogic/GameplayScene.h"
#include "../ScenesLogics/Menu/MenuScene.h"


Manager* Manager::m_instance = nullptr;

Manager::Manager() : m_actualScene(nullptr),  m_window(sf::VideoMode(800,800), "Shmup")
{
    GameplayScene* gameplayScene = new GameplayScene();
    m_scenes.insert({"Gameplay", gameplayScene});
    MenuScene* menuScene = new MenuScene();
    m_scenes.insert({"Menu", menuScene});
    m_test = sf::CircleShape(10.f);
    m_test.setOrigin({10.f, 10.f});
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
    LoadScene("Menu");
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
    if (m_actualScene != nullptr)
    {
        m_actualScene->Unload();
    }
    m_actualScene = m_scenes[a_sceneName];
    m_actualScene->Load();
    m_actualScene->Init();
}


void Manager::LoadScene(int a_index)
{
    if (m_actualScene != nullptr)
    {
        m_actualScene->Unload();
    }
    auto it = m_scenes.begin();
    std::advance(it, a_index);
    m_actualScene = it->second;
    m_actualScene->Load();
    m_actualScene->Init();
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
    m_window.setView(sf::View({400.f, 400.f}, {800, 800}));
    m_window.draw(m_test);
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
        if (event.type == sf::Event::MouseMoved)
        {
            m_test.setPosition({static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)});
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            m_test.setFillColor(sf::Color::Red);
        }

        
        m_actualScene->HandleEvent(event);
    }
}




