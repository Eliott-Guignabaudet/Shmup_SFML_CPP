#include "Scene.h"

#include "../Managers/DestructionManager.h"
#include "../Managers/RessourceManager.h"


Scene::Scene()
{
}

Scene::~Scene()
{
    for (ARenderStack* stack : m_renderStacks)
    {
        delete stack;
    }
    m_renderStacks.clear();
}

void Scene::Load()
{
    for (ARenderStack* stack : m_renderStacks)
    {
        stack->Load();
    }
}

void Scene::Unload()
{
    for (ARenderStack* stack : m_renderStacks)
    {
        DestructionManager::GetInstance()->AddPtrToDestroy(stack);
    }
    m_renderStacks.clear();
}

void Scene::Init()
{
    for (ARenderStack* stack : m_renderStacks)
    {
        stack->Init();
    }
}

void Scene::Update(sf::Time a_deltaTime)
{
    for (ARenderStack* stack : m_renderStacks)
    {
        stack->Update(a_deltaTime);
    }
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (ARenderStack* stack : m_renderStacks)
    {
        target.draw(*stack);
    }
}

void Scene::HandleEvent(sf::Event a_event)
{
    for (ARenderStack* stack : m_renderStacks)
    {
        stack->HandleEvent(a_event);
    }
}
