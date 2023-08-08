// SDLGAME.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include "Colour.h"
int GetIndex(SDL_Surface* surface, int row, int col) {
    return row * surface->w + col;
}
void SetPixel(SDL_Surface* surface, Uint32 colour, int x, int y) {
    SDL_LockSurface(surface);
    Uint32* p = (Uint32*)surface->pixels;
    int i = GetIndex(surface, y, x);
    p[i] = colour;
    SDL_UnlockSurface(surface);
}
int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Fail to Init." << std::endl;
    }
    SDL_Window* optrWindow = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0u);
    if (optrWindow == nullptr)
    {
        std::cout << "Get error: " << SDL_GetError() << std::endl;
    }
    SDL_Surface* noptrWindowSurface = SDL_GetWindowSurface(optrWindow);
    SDL_PixelFormat* format = noptrWindowSurface->format;
    Colour::InitFormat(format);
    Colour c = Colour(255, 255, 0, 0);
    SetPixel(noptrWindowSurface, c.GetPixelColour(), 400, 300);
    SDL_UpdateWindowSurface(optrWindow);
    SDL_Event sdl_e;
    bool isRunning = true;
    while (isRunning) {
        while (SDL_PollEvent(&sdl_e)) {
            switch (sdl_e.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            }
        }
    }
    SDL_DestroyWindow(optrWindow);
    SDL_Quit();
    return 0;
}
