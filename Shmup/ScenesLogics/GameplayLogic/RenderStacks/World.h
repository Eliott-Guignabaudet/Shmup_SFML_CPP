#pragma once
#include "../../ARenderStack.h"
#include "../Character/AICharacter.h"
#include "../Character/Player.h"
#include "../Character/ProjectilePool.h"

class World : public ARenderStack
{
private:
    std::vector<AEntity*> m_entities;
    Player m_player;
    std::vector<Projectile*> m_activeProjectiles;
    std::vector<AICharacter*> m_aiCharacters;
    ProjectilePool* m_pool;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    World();
    ~World() override;
    void Load() override;
    void Init() override;
    void Update(sf::Time a_deltaTime) override;
    void CheckProjectileCollisions(Projectile* a_projectile);
    void HandleEvent(sf::Event a_event) override;
    void ActiveProjectile(std::string a_tag, sf::Vector2f a_position, sf::Vector2f a_direction, std::string a_tileMap,std::pair<int, int> a_tileIndex, int a_tileSize, float a_speed);
    void DisableProjectile(Projectile* a_projectile);
    void RemoveAI(AICharacter* a_aiCharacter);
    void BlockPlayerInWorld();
};
