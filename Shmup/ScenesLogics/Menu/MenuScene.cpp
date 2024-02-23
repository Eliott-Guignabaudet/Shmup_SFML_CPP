#include "MenuScene.h"

#include "../../Managers/RessourceManager.h"
#include "RenderStacks/MenuUI.h"

MenuScene::MenuScene()
{
    
}

void MenuScene::Load()
{
    if (!RessourceManager::GetInstance()->LoadFont("Pixel", "Assets/Fonts/depixel/DePixelHalbfett.otf"))
    {
        
    }
    // if (!RessourceManager::GetInstance()->LoadFont("Arial", "Assets/Fonts/arial.ttf"))
    // {
    //     
    // }
    MenuUI* menuUI = new  MenuUI();
    m_renderStacks.push_back(menuUI);
    Scene::Load();
    // Load Font and sprites
}

void MenuScene::Unload()
{
    Scene::Unload();
    // Unload Fonts and sprites
    RessourceManager::GetInstance()->UnloadFont("Pixel");
}
