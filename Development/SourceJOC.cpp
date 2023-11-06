#include"HeaderJOC.h"


int main(int argc, char* args[])
{
	if (!init())
	{
		printf("failed to initialize! \n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("failed to load media! \n");
		}
		else
		{
			//SDL_BlitSurface(gHelloWorld, NULL, screenSurface, NULL);
			SDL_Event e;
			bool quit = false;
			while (!quit)
			{
				while (SDL_PollEvent(&e)!=0)
				{ 
					if (e.type == SDL_QUIT)
						quit = true;
				}
				/*
				SDL_Rect strechRect;
				strechRect.x = 0;
				strechRect.y = 0;
				strechRect.w = SCREEN_WIDTH;
				strechRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled(gHelloWorld, NULL, screenSurface, &strechRect);
				
				SDL_UpdateWindowSurface(window);
				*/
				SDL_RenderClear(renderer);
				SDL_RenderCopy(renderer, texture, NULL, NULL);
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
				SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
				SDL_RenderPresent(renderer);
				

			}
		}
	}
	close();

	return 0;
}
