#pragma once
#include <vector>
#include <SFML/System/NonCopyable.hpp>

class DestructionManager : public sf::NonCopyable
{
private:
    static DestructionManager* m_instance;
    std::vector<void*> m_ptrToDestroy;
    DestructionManager();
    ~DestructionManager();
public:
    static DestructionManager* GetInstance();
    void AddPtrToDestroy(void* a_ptr);
    void DestroyPtr();
    
};
