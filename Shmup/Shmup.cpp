// Shmup.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include <fstream>
#include "Managers/Manager.h"
#include <nlohmann/json.hpp>
#include "ScenesLogics/GameplayLogic/Character/Character.h"
using json = nlohmann::json;
int main()
{
    std::cout << "Hello World!\n";

#ifdef _DEBUG
    std::cout << "DEBUG BUILD" << std::endl;
#else
    std::cout << "RELEASE BUILD" << std::endl;
#endif
    
    // Character* myCharacter = new Character();
    // delete myCharacter;
    // myCharacter = NULL;
    // if (myCharacter != nullptr)
    // {
    //     delete myCharacter;
    // }
    

     //This will print the entire json object.

    Manager::GetInstance()->Run();
}


