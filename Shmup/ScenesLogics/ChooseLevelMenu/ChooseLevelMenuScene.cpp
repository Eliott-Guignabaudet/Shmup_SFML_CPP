#include "ChooseLevelMenuScene.h"

#include "../../Managers/RessourceManager.h"
#include "RenderStacks/ChooseLevelMenuUI.h"

ChooseLevelMenuScene::ChooseLevelMenuScene()
{
}

void ChooseLevelMenuScene::Load()
{
    if (!RessourceManager::GetInstance()->LoadFont("Pixel", "Assets/Fonts/depixel/DePixelHalbfett.otf"))
    {
        
    }
    ChooseLevelMenuUI* chooseLevelMenu = new  ChooseLevelMenuUI();
    m_renderStacks.push_back(chooseLevelMenu);
    Scene::Load();
}

void ChooseLevelMenuScene::Unload()
{
    Scene::Unload();
    RessourceManager::GetInstance()->UnloadFont("Pixel");

}
