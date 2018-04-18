#include "Window.h"

using namespace std;

Window::Window(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        cerr << "SDL failed to init: " << SDL_GetError() << endl;
        throw;
    }

    // SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    // SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    // SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    // SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    // SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // window = SDL_CreateWindow("Apteuic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL );

    window = SDL_CreateWindow("Apteuic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );

    if (window == NULL)
        throw;

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);


    context = SDL_GL_CreateContext(window);
}


Window::~Window()
{
    SDL_DestroyWindow(window);

    SDL_Quit();
}

Tile::Tile(int x,int y,int z){

    SDL_Rect r;
    r.x = TileSizeX * x;
    r.y = TileSizeY * y;
    r.w = TileSizeX;
    r.h = TileSizeY;
    Rect = r;

}