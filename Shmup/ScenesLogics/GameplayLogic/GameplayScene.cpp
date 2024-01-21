#include <iostream>
#include "GameplayScene.h"
#include "RenderStacks/BackGround.h"
#include "RenderStacks/World.h"
#include "../../Managers/RessourceManager.h"

GameplayScene::GameplayScene()
{
    BackGround* backgroundStack = new BackGround();
    World* worldStack = new World();

    m_renderStacks.push_back(backgroundStack);
    m_renderStacks.push_back(worldStack);
}

void GameplayScene::Load()
{
    Scene::Load();
    if (RessourceManager::GetInstance()->LoadTexture("Ships", "Assets/kenney_pixel-shmup/Tilemap/ships_packed.png"))
    {
        // error
    }
    if (RessourceManager::GetInstance()->LoadTexture("Tiles", "Assets/kenney_pixel-shmup/Tilemap/tiles_packed.png"))
    {
        
    }
}

