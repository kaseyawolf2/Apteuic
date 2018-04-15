#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Window
{
public:
    Window(int width, int height);
    ~Window();
    SDL_Window *window;
    SDL_GLContext context;
};