#include "ProjectilePool.h"

ProjectilePool::ProjectilePool() : m_projectiles()
{
}

ProjectilePool::ProjectilePool(int a_projectileNb)
{
    for (int i = 0; i < a_projectileNb; ++i)
    {
        Projectile* projectile = new Projectile();
        m_projectiles.push_back(projectile);
    }
}

ProjectilePool::~ProjectilePool()
{
    for (Projectile* projectile : m_projectiles)
    {
        delete projectile;
    }
    m_projectiles.clear();
}

Projectile* ProjectilePool::GetProjectile()
{
    if (!m_projectiles.empty())
    {
        Projectile* projectile = m_projectiles.back();
        m_projectiles.pop_back();
        return  projectile;
    }

    return new Projectile();
    
}

void ProjectilePool::InsertProjectile(Projectile* a_projectile)
{
    a_projectile->Reset();
    m_projectiles.push_back(a_projectile);
}
