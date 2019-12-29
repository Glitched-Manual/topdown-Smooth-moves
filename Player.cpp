#include "Player.h"

Player::Player()
{
	LoadInputMap();
}

Player::Player(double passed_x, double passed_y, double passed_w, double passed_h)
{
	SetPlayerRect(passed_x, passed_y, passed_w, passed_h);
	LoadInputMap();
}

Player::~Player()
{

}

void Player::SetGameEvent(SDL_Event* passed_event)
{
	
	game_event = passed_event;

}

void Player::LoadPlayerFigure(SDL_Renderer* passed_renderer)
{
	player_texture = IMG_LoadTexture(passed_renderer, "resources/bb-8.jpg");

	if (player_texture == NULL)
	{
		printf("Circle_Shape::CreateShapeTexture error - %s\n", IMG_GetError());
	
	}
}

void Player::Draw(SDL_Renderer* passed_renderer)
{
	if (player_texture != NULL)
	{
		SDL_RenderCopyEx(passed_renderer, player_texture, NULL, player_base_rect, 0.0, NULL, SDL_FLIP_NONE);
	}
	else
	{
		printf("player_texture == NULL\n");
	}
		
}

void Player::SetPlayerRect(double passed_x, double passed_y, double passed_w, double passed_h)
{
	if (player_base_rect == NULL)
	{
		player_base_rect = new SDL_Rect;
	}
	player_base_rect->x = passed_x;
	player_base_rect->y = passed_y;
	player_base_rect->w = passed_w;
	player_base_rect->h = passed_h;

}
void Player::MovePlayerFigure(double passed_x, double passed_y)
{
	if (player_base_rect != NULL)
	{
		
		SetPlayerRect(passed_x, passed_y, player_base_rect->w, player_base_rect->h);

	}
}

void Player::Clean()
{

}


void Player::LoadInputMap()
{
	easy_sdl2_Input_Map["UP"] = UP;
	easy_sdl2_Input_Map["DOWN"] = DOWN;
	easy_sdl2_Input_Map["LEFT"] = LEFT;
	easy_sdl2_Input_Map["RIGHT"] = RIGHT;
	easy_sdl2_Input_Map["START"] = START;
	easy_sdl2_Input_Map["SELECT"] = SELECT;
	easy_sdl2_Input_Map["A_ACTION"] = A_ACTION;
	easy_sdl2_Input_Map["B_ACTION"] = B_ACTION;
	easy_sdl2_Input_Map["ESCAPE"] = ESCAPE;
	easy_sdl2_Input_Map["SPACE"] = SPACE;
	easy_sdl2_Input_Map["LEFT_CLICK"] = LEFT_CLICK;
	easy_sdl2_Input_Map["RIGHT_CLICK"] = RIGHT_CLICK;
}

bool Player::ButtonInputCheck(std::string input_to_check)
{
	switch (easy_sdl2_Input_Map[input_to_check])
	{
	case UP:

		if (game_event->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP) return true;

		else if (game_event->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP) return true;

		else if ((game_event->key.keysym.sym == SDLK_UP)) return true;

		else return false;

		break;

	case DOWN:

		if (game_event->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN) return true;

		else if ((game_event->key.keysym.sym == SDLK_DOWN)) return true;

		else return false;

		break;

	case LEFT:

		if (game_event->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT) return true;

		else if ((game_event->key.keysym.sym == SDLK_LEFT)) return true;

		else return false;

		break;

	case RIGHT:

		if (game_event->cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT) return true;

		else if ((game_event->key.keysym.sym == SDLK_RIGHT)) return true;

		else return false;

		break;
	case START:

		if (game_event->cbutton.button == SDL_CONTROLLER_BUTTON_START) return true;

		else if ((game_event->key.keysym.sym == SDLK_RETURN)) return true;

		else return false;

		break;

	case SELECT:

		if (game_event->cbutton.button == SDL_CONTROLLER_BUTTON_GUIDE) return true;

		else if ((game_event->key.keysym.sym == SDLK_TAB)) return true;

		else return false;

		break;

	case A_ACTION:

		if (game_event->cbutton.button == SDL_CONTROLLER_BUTTON_A) return true;

		else if ((game_event->key.keysym.sym == SDLK_a)) return true;

		else return false;

		break;

	case B_ACTION:

		/* game_event->cbutton.button == SDL_CONTROLLER_BUTTON_B is true when any keyboard key pressed

		   any keyboard key game_event->cbutton.button == 1
			SDL_CONTROLLER_BUTTON_B == 1

			game_event->cbutton.button == SDL_CONTROLLERBUTTONDOWN used
		*/
		if ((game_event->cbutton.button == SDL_CONTROLLER_BUTTON_B))
		{
			
				std::cout << "B pressed" << std::endl;
			

			return true;

		}


		else if ((game_event->key.keysym.sym == SDLK_s))
		{
			
				std::cout << "S pressed" << std::endl;
			

			return true;
		}

		else return false;

		break;

	case ESCAPE:
		//keyboard only
		if ((game_event->key.keysym.sym == SDLK_ESCAPE))
		{
			
				std::cout << "ESCAPE pressed" << std::endl;
			

			return true;
		}

		else return false;

		break;

	case SPACE:
		//keyboard only
		if ((game_event->key.keysym.sym == SDLK_SPACE)) return true;

		else return false;

		break;

	case LEFT_CLICK:
		//mouse only
		if ((game_event->button.button == SDL_BUTTON_LEFT)) return true;

		else return false;

		break;

	case RIGHT_CLICK:
		//mouse only
		if ((game_event->button.button == SDL_BUTTON_RIGHT)) return true;

		else return false;

		break;

	default:

		return false;
		break;
	}

	return false;
}

void Player::PlayerEvent()
{

	//player_move_up, player_move_down, player_move_left, player_move_right;

	/*

	UP

	*/

	if (ButtonInputCheck("UP"))
	{
		player_move_up = true;
	}
	else
	{
		player_move_up = false;
	}

	/*

	 Down

	*/

	if (ButtonInputCheck("DOWN"))
	{
		player_move_down = true;
	}
	else
	{
		player_move_down = false;
	}


	/*

	 LEFT

	*/

	if (ButtonInputCheck("LEFT"))
	{
		player_move_left = true;
	}
	else
	{
		player_move_left = false;
	}

	/*

	 RIGHT

	*/

	if (ButtonInputCheck("RIGHT"))
	{
		player_move_right = true;
	}
	else
	{
		player_move_right = false;
	}


	/*
	old movement

	*/

	if (game_event > 0)
	{
		/*up down left right*/
		if (player_move_up)
		{
			/*
			  up left, up right

			  else do normal
			*/

			if (player_move_left)
			{
				SetDiagonalMovement(player_movement);	// 				 

				MovePlayerFigure(player_base_rect->x - diagonal_x, player_base_rect->y - diagonal_y);
			}
			else if (player_move_right)
			{
				SetDiagonalMovement(player_movement);

				MovePlayerFigure(player_base_rect->x + diagonal_x, player_base_rect->y - diagonal_y);
			}
			else
			{
				MovePlayerFigure(player_base_rect->x, player_base_rect->y - 10.7);
			}




		}
		else if (player_move_down)
		{
			/*
			  down left, down right

			  else do normal
			*/
			if (player_move_left)
			{
				SetDiagonalMovement(player_movement);

				MovePlayerFigure(player_base_rect->x - diagonal_x, player_base_rect->y + diagonal_y);
			}
			else if (player_move_right)
			{
				SetDiagonalMovement(player_movement);

				MovePlayerFigure(player_base_rect->x + diagonal_x, player_base_rect->y + diagonal_y);
			}
			else
			{
				MovePlayerFigure(player_base_rect->x, player_base_rect->y + 10.7);
			}

		}
		else if (player_move_left)
		{


			MovePlayerFigure(player_base_rect->x - 10.7, player_base_rect->y);
		}
		else if (player_move_right)
		{


			MovePlayerFigure(player_base_rect->x + 10.7, player_base_rect->y);
		}


		//printf("Player_Character::PlayerEvent() called\n");
	}
}


void Player::SetDiagonalMovement(double passed_c_side)
{
	double a_side;
	double b_side;

	double c_side = pow(passed_c_side, 2);;

	a_side = c_side / 2;
	a_side = sqrt(a_side);

	b_side = a_side;

	diagonal_x = a_side;
	diagonal_y = b_side;
}