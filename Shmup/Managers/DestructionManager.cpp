#include "DestructionManager.h"

DestructionManager* DestructionManager::m_instance = nullptr;

DestructionManager::DestructionManager() : m_ptrToDestroy()
{
}

DestructionManager::~DestructionManager()
{
}

DestructionManager* DestructionManager::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new DestructionManager();
    }
    return m_instance;
}

void DestructionManager::AddPtrToDestroy(void* a_ptr)
{
    m_ptrToDestroy.push_back(a_ptr);
}

void DestructionManager::DestroyPtr()
{
    for (auto element : m_ptrToDestroy)
    {
        delete element;
    }
    m_ptrToDestroy.clear();
}
