#include "HeaderJOC.h"

SDL_Window* window=NULL;
SDL_Surface* screenSurface=NULL;
SDL_Surface* gHelloWorld=NULL;

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("SDL tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("window could not be created! SDL error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return success;
}
bool loadMedia()
{
	bool success = true;
	gHelloWorld=loadSurface("TESTimages/hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Zabara_Sonia_JOC/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}
void close()
{
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(window);         //screenSurface este dat free funct loadSurface
 	window = NULL;

	SDL_Quit();
}
SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL error: %s", path.c_str(), IMG_GetError());
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL error: %s", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}