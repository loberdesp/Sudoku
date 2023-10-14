#pragma once

#include "game.h"

class TextureManager {

    //std::vector<SDL_Texture> textureVector;


    public:
        static SDL_Texture *LoadTexture(const char* fileName, SDL_Renderer *ren);
        void loadAllTxt();
};


//next step is loading all textures to vector in texturemanager