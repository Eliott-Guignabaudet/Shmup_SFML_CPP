#pragma once
#include <vector>
#include <nlohmann/json_fwd.hpp>

#include "AICharacter.h"
#include "AiCharacterSpawn.h"

class AICharacterSpawner
{
private:
    std::vector<AiCharacterSpawn> m_aiCharactersToSpawn;
    float m_timeElpased;
    void SpawnAI(int a_index);
    std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> m_shootCallBack;

    AiCharacterSpawn TransformSpawnDataToStruct(nlohmann::json a_data);
public:
    AICharacterSpawner();
    AICharacterSpawner(std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> a_shootCallBack);
    AICharacterSpawner(nlohmann::json* a_levelData, std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> a_shootCallBack);
    std::vector<AICharacter*> ActiveCharacters;
    void Update(sf::Time a_deltaTime);
    bool IsSpawnerFinished();
    void RemoveAi(AICharacter* a_aiCharacter);
};
