#include "AICharacterSpawner.h"

#include <iostream>

#include "AIShootVertical.h"
#include "AiSuicideCharacter.h"

AICharacterSpawner::AICharacterSpawner()
{
    
}

AICharacterSpawner::AICharacterSpawner(std::function<void(std::string , sf::Vector2f , sf::Vector2f , std::string ,std::pair<int, int>, int,  float)> a_shootCallBack) :
    m_timeElpased(0),
    m_aiCharactersToSpawn(),
    m_shootCallBack(a_shootCallBack)
{
    m_aiCharactersToSpawn = {
        {{100, -200}, {-1, 1}, 1, "ShootVertical", false},
        {{100, -200}, {-1, 1}, 3, "ShootVertical", false},
        {{100, -200}, {-1, 1}, 5, "ShootVertical", false},
        {{-200, -200}, {1, 1}, 4, "ShootVertical", false},
        {{0, 0}, {0, 0}, 10, "", false},
    };
}

void AICharacterSpawner::SpawnAI(int a_index)
{
    AiCharacterSpawn* spawn = &m_aiCharactersToSpawn[a_index];
    if (spawn->AICharacterType == "ShootVertical")
    {
        AIShootVertical* newAi = new AIShootVertical(spawn->SpawnPosition, spawn->SpawnDirection, 100, 5, 0.5f, m_shootCallBack);
        newAi->Load();
        newAi->Init();
        ActiveCharacters.push_back(newAi);
    }
    if (spawn->AICharacterType == "Suicide")
    {
        AiSuicideCharacter* newAi = new AiSuicideCharacter(spawn->SpawnPosition, spawn->SpawnDirection, 10000, 1);
        newAi->Load();
        newAi->Init();
        ActiveCharacters.push_back(newAi);
    }
    spawn->IsSpawned = true;
    
}

void AICharacterSpawner::Update(sf::Time a_deltaTime)
{
    m_timeElpased += a_deltaTime.asSeconds();
    for (int i = 0; i < m_aiCharactersToSpawn.capacity(); ++i)
    {
        if (m_aiCharactersToSpawn[i].SpawnTime <= m_timeElpased && !m_aiCharactersToSpawn[i].IsSpawned)
        {
            SpawnAI(i);
        }
    }
}

bool AICharacterSpawner::IsSpawnerFinished()
{
    for (int i = 0; i < m_aiCharactersToSpawn.capacity(); ++i)
    {
        if (m_aiCharactersToSpawn[i].IsSpawned == false)
        {
            return false;
        }
    }
    return ActiveCharacters.size() == 0;
}

void AICharacterSpawner::RemoveAi(AICharacter* a_aiCharacter)
{
    delete a_aiCharacter;
    std::vector<AICharacter*>::iterator index = std::find(
        ActiveCharacters.begin(), ActiveCharacters.end(), a_aiCharacter);
    ActiveCharacters.erase(index);
}
