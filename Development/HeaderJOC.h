#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

extern SDL_Window* window;
extern SDL_Surface* screenSurface;
extern SDL_Surface* gHelloWorld;
extern SDL_Renderer* renderer;
extern SDL_Texture* texture;

const int SCREEN_WIDTH = 640;            //schimbarea rezolutiei joc prin schimbarea acestor valori(prin optimizare nu ne mai temem de rezolutie
const int SCREEN_HEIGHT = 480;

bool init();                                      //initializeaza fereastra sdl
bool loadMedia();                                 //pune pe fundal imaginea
void close();                                     //inchide si elibereza memoria
SDL_Surface* loadSurface(std::string path);       //optimizeaza imaginea
SDL_Texture* loadTexture(std::string path);