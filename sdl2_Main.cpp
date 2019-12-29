#include <iostream>

#include "cross_sdl.h"
#include "Player.h"

SDL_Window* game_window = NULL;
SDL_Event* game_event = NULL;
SDL_Renderer* game_renderer = NULL;

int* SCREEN_WIDTH = new int(720);
int* SCREEN_HEIGHT = new int(720);



Player* p1;

bool* QUIT_GAME;

bool CreateSDL2Window()
{
	//only called when the window is NULL

	if (game_window == NULL)
	{
		game_window = SDL_CreateWindow("Smooth Moves", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, *SCREEN_WIDTH, *SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (game_window == NULL)
		{

			printf("CSDL::createSDLWindow error: SDL2_Window could not be created! SDL Error: %s\n", SDL_GetError());

			return false;
		}
	}
	
	printf("Window was created.\n");

	return true;
}

bool CreateSDL2Event()
{
	if (game_event == NULL)
	{
		game_event = new SDL_Event;
	}
	printf("Event was initialized.\n");

	return true;
}

bool CreateSDL2Renderer()
{
	if (game_renderer == NULL)
	{
		game_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED);

		if (game_renderer == NULL)
		{

			{
				printf("CSDL::createSDLRenderer() error: Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			}

		}
	}
		

	return true;
}


bool Init()
{
	/*
	init window renderer and event
	
	*/

	if (QUIT_GAME == NULL)
	{
		QUIT_GAME = new bool;

		*QUIT_GAME = false;
	}

	

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{

		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");

			return false;
		}

		//Create window

		if (!CreateSDL2Window())
		{
			return false;
		}
		else
		{

			//initialize event

			if (CreateSDL2Event())
			{

			}

			// create renderer
			if (!CreateSDL2Renderer())
			{
				
				return false;
			}
			else
			{

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					// return false;
				}

				// setup audio if it loaded

				if (SDL_WasInit(SDL_INIT_AUDIO) != 0)
				{
					
						printf("Audio has been initialized.\n");
					
					//Initialize SDL_mixer - uncomment return later
					if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
					{
						
							printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
						
						
					//	return false;
					}
				}
				else
				{

						printf("Audio was not initialized! SDL_mixer Error: %s\n", Mix_GetError());
					
					// return false;
				}
				
				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					
					// return false;
				}
				
			}
		}
	}
	


	return true;

}

void LoadResources()
{
	if (p1 == NULL)
	{
		p1 = new Player(0,0,100,100);
		p1->SetGameEvent(game_event);
		p1->LoadPlayerFigure(game_renderer);
		
	}
}

void RenderTextures()
{
	if (p1 != NULL)
	{
		p1->Draw(game_renderer);
	}
	else
	{
		printf("p1 == NULL\n");
	}
}

void GameLoop()
{		
	printf("GameLoop started.\n");
	LoadResources();
	
	//window background color
	SDL_SetRenderDrawColor(game_renderer, 0, 0, 0, 255);
		


	while ((game_event->type != SDL_QUIT) && (*QUIT_GAME == false))
	{
				
		while (SDL_PollEvent(game_event) > 0)
		{
			p1->PlayerEvent();
		}

		//Clear screen
		//SDL_SetRenderDrawColor(game_renderer, 255, 255, 255, 255);

		SDL_SetRenderDrawColor(game_renderer, 0, 0, 0, 255);

		SDL_RenderClear(game_renderer);
				


		//render

		RenderTextures();

		
		SDL_RenderPresent(game_renderer);
	}

}


int main(int argc, char** argv)
{
	//INIT
	Init();

	
	//gameloop
	GameLoop();
    return 0;
}