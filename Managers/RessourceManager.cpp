#include <filesystem>
#include "RessourceManager.h"
#include <Windows.h>

RessourceManager* RessourceManager::m_instance = nullptr;

RessourceManager::RessourceManager()
= default;

RessourceManager* RessourceManager::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new RessourceManager();
    }
    return m_instance;
}

bool RessourceManager::LoadTexture(std::string a_name, std::string a_fileName)
{
    TCHAR buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, sizeof(buffer));
    
    sf::Texture* texture = new sf::Texture();
    if (!texture->loadFromFile(std::filesystem::path(buffer).parent_path().string() +"/"+ a_fileName))
    {
        delete texture;
        return false;
    }
    m_textures.insert({a_name, texture});
    return true;
}

void RessourceManager::UnloadTexture(std::string a_name)
{
    delete m_textures[a_name];
    m_textures.erase(a_name);
}

sf::Texture* RessourceManager::GetTexture(std::string a_name)
{
    return m_textures[a_name];
}
