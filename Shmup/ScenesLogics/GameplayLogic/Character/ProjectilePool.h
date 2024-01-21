#pragma once
#include <vector>

#include "Projectile.h"

class ProjectilePool
{
private:
    std::vector<Projectile*> m_projectiles;
public:
    ProjectilePool();
    ~ProjectilePool();
    ProjectilePool(int a_projectileNb);
    Projectile* GetProjectile();
    void InsertProjectile(Projectile* a_projectile);
};
