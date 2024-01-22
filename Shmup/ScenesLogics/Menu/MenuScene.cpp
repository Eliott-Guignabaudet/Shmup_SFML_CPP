#include "MenuScene.h"

#include "RenderStacks/MenuUI.h"

MenuScene::MenuScene()
{
    
}

void MenuScene::Load()
{
    MenuUI* menuUI = new  MenuUI();
    m_renderStacks.push_back(menuUI);
    Scene::Load();
    // Load Font and sprites
}

void MenuScene::Unload()
{
    Scene::Unload();
    // Unload Fonts and sprites
}
