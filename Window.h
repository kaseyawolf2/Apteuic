#pragma once
#include "defines.h"
#include <iostream>
#include <SDL2/SDL.h>

class Window
{
public:
    Window(int width, int height);
    ~Window();
    SDL_Window *window;
    SDL_GLContext context;
    SDL_Renderer *renderer;
};

class Tile {
public:
    Tile(int x,int y,int z);
    SDL_Rect Rect;
};