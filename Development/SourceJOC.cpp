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
			while (quit == false)
			{
				while (SDL_PollEvent(&e)!=0)
				{ 
					if (e.type == SDL_QUIT)
						quit = true;
				}
				SDL_Rect strechRect;
				strechRect.x = 0;
				strechRect.y = 0;
				strechRect.w = SCREEN_WIDTH;
				strechRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled(gHelloWorld, NULL, screenSurface, &strechRect);

				SDL_UpdateWindowSurface(window);
			}
		}
	}
	close();

	return 0;
}
