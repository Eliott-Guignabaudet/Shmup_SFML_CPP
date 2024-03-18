#pragma once
#include "../Scene.h"

class GameplayScene : public Scene
{
private:
    nlohmann::json* m_levelData;
public:
    GameplayScene();
    void Load() override;
    void Unload() override;
};
