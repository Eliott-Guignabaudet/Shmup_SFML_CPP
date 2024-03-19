// Shmup.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include "Managers/Manager.h"
#include <nlohmann/json.hpp>
#include <noise/noise.h>
#include <noise/noiseutils.h>
using namespace noise;
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

    
    // utils::RendererImage renderer;
    // utils::Image image;
    // renderer.SetSourceNoiseMap (heightMap);
    // renderer.SetDestImage (image);
    // renderer.Render ();
    //
    // utils::WriterBMP writer;
    // writer.SetSourceImage (image);
    // writer.SetDestFilename ("tutorial3.bmp");
    // writer.WriteDestFile ();
    
    Manager::GetInstance()->Run();
}


