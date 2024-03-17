#include "GameOverScene.h"

#include "../../Managers/RessourceManager.h"
#include "RenderStacks/GameOverMenuUI.h"

GameOverScene::GameOverScene()
{
    
}

void GameOverScene::Load()
{
    if (!RessourceManager::GetInstance()->LoadFont("Pixel", "Assets/Fonts/depixel/DePixelHalbfett.otf"))
    {
        
    }
    // if (!RessourceManager::GetInstance()->LoadFont("Arial", "Assets/Fonts/arial.ttf"))
    // {
    //     
    // }
    GameOverMenuUI* menuUI = new  GameOverMenuUI();
    m_renderStacks.push_back(menuUI);
    Scene::Load();
    // Load Font and sprites
}

void GameOverScene::Unload()
{
    Scene::Unload();
    // Unload Fonts and sprites
    RessourceManager::GetInstance()->UnloadFont("Pixel");
}
