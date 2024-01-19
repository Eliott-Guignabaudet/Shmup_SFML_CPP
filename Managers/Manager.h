#pragma once
#include "../ScenesLogics/Scene.h"

class Manager
{
private:
    int m_actualSceneIndex;
    std::vector<Scene*> m_scenes;
    sf::Clock m_clock;
    sf::RenderWindow m_window;

    void Init();
    void Update(sf::Time a_deltaTime);
    void Draw();
    void HandleEvent();
public:
    Manager();
    ~Manager();
    void Run();
    void LoadScene(int a_index);
    
};
