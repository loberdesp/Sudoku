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
        bool isMouseinCurrSquare();
        void calcSquare();

        void newLine(bool orientation, int pos, int i);
        void drawLine(bool orientation, bool bold, int pos);
        void drawNet();
        void drawHighlight();

    private:
        bool isRunning;
        int mouseX, mouseY;
        int currSquareX, currSquareY;
        SDL_Rect r;


        SDL_Window *window;
        SDL_Renderer *renderer;

};