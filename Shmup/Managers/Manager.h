#pragma once
#include "../ScenesLogics/Scene.h"

class Manager: public sf::NonCopyable
{
private:
    Scene* m_actualScene;
    std::map<std::string, Scene*> m_scenes;
    sf::Clock m_clock;
    sf::RenderWindow m_window;

    static Manager* m_instance;

    sf::CircleShape m_test;
    
    void Init();
    void Update(sf::Time a_deltaTime);
    void Draw();
    void HandleEvent();
    Manager();
    ~Manager();
public:
    void Run();
    void LoadScene(int a_index);
    void LoadScene(std::string a_sceneName);
    static Manager* GetInstance();
};
