#include "game.h"
#include "TextureManager.h"

SDL_Texture *txt;
SDL_Rect srcR, destR;
TextureManager txtManager;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystem initialized!.." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    txtManager.loadAllTxt();
    txt = txtManager.LoadTexture("../assets/txt.png", renderer);
    
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
        break;
        case SDL_MOUSEBUTTONDOWN:
            std::cout << "klik" << std::endl;
        break;
        default:
        break;
    }
}

void Game::update() {
    destR.h = 100;
    destR.w = 100;
    srcR.h = 16;
    srcR.w = 16;
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, txt, &srcR, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}