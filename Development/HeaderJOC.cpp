#include "HeaderJOC.h"

SDL_Window* window=NULL;
SDL_Surface* screenSurface=NULL;
SDL_Surface* gHelloWorld=NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;

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
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1"))
		{
			printf("Warning: Linear texture filtering not enabled! \n");
		}

		window = SDL_CreateWindow("SDL tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (window == NULL)
		{
			printf("window could not be created! SDL error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("renderer could not be created! SDDL error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image error: %s \n", IMG_GetError());
					success = false;
				}
			}
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return success;
}
bool loadMedia()
{
	bool success = true;
	/*
	gHelloWorld = loadSurface("TESTimages/hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Zabara_Sonia_JOC/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
	*/
	texture = loadTexture("TESTimages/texture.png");
	if (texture == NULL)
	{
		printf("Unable to load texture image texture.png %s",SDL_GetError());
		success = false;
	}
	return success;
}
void close()
{
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}

	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
	}

	if (gHelloWorld != NULL)
	{
		SDL_FreeSurface(gHelloWorld);
		gHelloWorld = NULL;
	}

	if (window != NULL)
	{
		SDL_DestroyWindow(window);         //screenSurface este dat free funct loadSurface
		window = NULL;
	}

	IMG_Quit();
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
SDL_Texture* loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("unable to create texture from %s! SDL error: %s\n", path.c_str(), SDL_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
		if (newTexture == NULL)
		{
			printf("unable to create texture from %s! SDL error: %s", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}