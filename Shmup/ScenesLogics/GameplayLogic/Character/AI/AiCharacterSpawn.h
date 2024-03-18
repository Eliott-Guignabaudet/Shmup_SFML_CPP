#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

#include "AiCharacterType.h"

struct AiCharacterSpawn
{
public:
    sf::Vector2f SpawnPosition;
    sf::Vector2f SpawnDirection;
    float SpawnTime;
    AiCharacterType CharacterType;
    bool IsSpawned;
};
