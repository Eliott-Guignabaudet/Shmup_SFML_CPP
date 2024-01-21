// Shmup.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include "Managers/Manager.h"
#include "ScenesLogics/GameplayLogic/Character/Character.h"

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
    
    Manager::GetInstance()->Run();
}


