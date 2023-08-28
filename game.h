class Game {

    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }
        void getMouse(int *x, int *y);

        void newLine(bool orientation, int pos, int i);
        void drawLine(bool orientation, bool bold, int pos);
        void drawNet();

    private:
        bool isRunning;
        int mouseX, mouseY;
        SDL_Window *window;
        SDL_Renderer *renderer;

};