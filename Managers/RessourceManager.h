#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class RessourceManager : public sf::NonCopyable
{
private:
    static RessourceManager* m_instance;
    std::map<std::string , sf::Texture*> m_textures;
    std::map<std::string, sf::Font*> m_fonts;
public:
    RessourceManager();
    static RessourceManager* GetInstance();
    bool LoadTexture(std::string a_name, std::string a_fileName);
    bool LoadFont(std::string a_name, std::string a_fileName);
    
    void UnloadTexture(std::string a_name);
    void UnloadFont(std::string a_name);
    
    sf::Texture* GetTexture(std::string a_name);
    sf::Font* GetFont(std::string a_name);
    
};
