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
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
        break;
        case SDL_MOUSEMOTION:
            getMouse(&mouseX,&mouseY);
        break;
        default:
            break;
    }
}

void Game::update() {
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    drawNet();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}







//DRAWING GAME GRID

void Game::newLine(bool orientation, int pos, int i) {
    if(orientation) {
        SDL_RenderDrawLine(renderer, pos+i, 0, pos+i, WINDOW_SIZE);
    } else {
        SDL_RenderDrawLine(renderer, 0, pos+i, WINDOW_SIZE, pos+i);
    }
}

void Game::drawLine(bool orientation, bool bold, int pos) {
    int i=0;
    if(bold) {
        for(i=-1;i<2;i++) {
            newLine(orientation, pos, i);
        }
    } else {
        newLine(orientation, pos, i);
    }
}

void Game::drawNet() {
    for(int i=0;i<2;i++) {
        for(int j=0;j<WINDOW_SIZE/10;j++) {
            if(j%3==0) {
                drawLine(i, 1, j*WINDOW_SIZE/9);
            } else {
                drawLine(i, 0, j*WINDOW_SIZE/9);
            }
        }
    }
}






//CURRENT SQUARE HIGHLIGHT

void Game::getMouse(int *x, int *y) {
    SDL_GetMouseState(x, y);
    std::cout << *x << ":" << *y << std::endl;
}