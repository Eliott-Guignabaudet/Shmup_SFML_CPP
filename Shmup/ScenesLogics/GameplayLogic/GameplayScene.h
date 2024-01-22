#pragma once
#include "../Scene.h"

class GameplayScene : public Scene
{
public:
    GameplayScene();
    void Load() override;
    void Unload() override;
};
