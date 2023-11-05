#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

extern SDL_Window* window;
extern SDL_Surface* screenSurface;
extern SDL_Surface* gHelloWorld;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface(std::string path);