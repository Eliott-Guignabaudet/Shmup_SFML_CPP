#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

struct AiCharacterSpawn
{
public:
    sf::Vector2f SpawnPosition;
    sf::Vector2f SpawnDirection;
    float SpawnTime;
    std::string AICharacterType;
    bool IsSpawned;
};
