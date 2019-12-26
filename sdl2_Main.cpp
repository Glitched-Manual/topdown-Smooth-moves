#include <iostream>


#include "cross_sdl.h"

SDL_Window* game_window = NULL;
SDL_Event* game_event = NULL;
SDL_Renderer* game_renderer = NULL;

bool* QUIT_GAME;

bool Init()
{
	/*
	init window renderer and event
	
	*/
}


void GameLoop()
{
	

	
	//use quit_game_from_inputto quit game 
	//color background
	SDL_SetRenderDrawColor(game_renderer, 0, 0, 0, 255);

	
	


	while ((game_event->type != SDL_QUIT) && (*QUIT_GAME == false))
	{
		//software_text_manager->SetRenderAppTextFalse();




		while (SDL_PollEvent(game_event) > 0)
		{

			
		}

		//Clear screen
		SDL_SetRenderDrawColor(game_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		SDL_RenderClear(game_renderer);

		


		//render

		//RenderAppTextures();

		/*
		handle events

		key board and controller
		*/

		//update

		//Update();

		//clean

		SDL_RenderPresent(game_renderer);
	}

}


int main()
{
	//INIT

	//gameloop

    return 0;
}