#pragma once
#include "../Scene.h"

class GameOverScene : public Scene
{
public:
    GameOverScene();
    void Load() override;
    void Unload() override;
};
