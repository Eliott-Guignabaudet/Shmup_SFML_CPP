#include <iostream>
#include "GameplayScene.h"

#include <fstream>

#include "RenderStacks/BackGround.h"
#include "RenderStacks/World.h"
#include "../../Managers/RessourceManager.h"

GameplayScene::GameplayScene() : m_levelData()
{
    
}

void GameplayScene::Load()
{
    
    if (!RessourceManager::GetInstance()->LoadTexture("Ships", "Assets/kenney_pixel-shmup/Tilemap/ships_packed.png"))
    {
        std::cout << "Fail to load Ships" << std::endl;
    }
    if (!RessourceManager::GetInstance()->LoadTexture("Tiles", "Assets/kenney_pixel-shmup/Tilemap/tiles_packed.png"))
    {
        std::cout << "Fail to load Tiles" << std::endl;
    }
    if (!RessourceManager::GetInstance()->LoadFont("Pixel", "Assets/Fonts/depixel/DePixelHalbfett.otf"))
    {
        std::cout << "Fail to load Font Pixel" << std::endl;
    }

    std::ifstream  ifs("./Data/LevelDatas.json");
    if (ifs)
    {
        nlohmann::json jsonData = nlohmann::json::parse(ifs);
        if (jsonData != NULL)
        {
            m_levelData = new nlohmann::json();
            *m_levelData = jsonData["Levels"][0];
            std::cout << *m_levelData << std::endl;
        }
        
        
    }
    else
    {
        std::cout << "Can't read level data" << std::endl; 
    }

    BackGround* backgroundStack = new BackGround();
    World* worldStack = new World(m_levelData);

    m_renderStacks.push_back(backgroundStack);
    m_renderStacks.push_back(worldStack);
    // Load Render Stacks
    Scene::Load();
}

void GameplayScene::Unload()
{
    Scene::Unload();
    RessourceManager::GetInstance()->UnloadTexture("Ships");
    RessourceManager::GetInstance()->UnloadTexture("Tiles");
    RessourceManager::GetInstance()->UnloadFont("Pixel");
    delete m_levelData;


}

