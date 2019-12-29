#include <iostream>
#include <map>
#include <cmath>

#include "cross_sdl.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:

	SDL_Rect* player_base_rect;
	SDL_Texture* player_texture;
	SDL_Event* game_event;

	enum ButtonValue { UP, DOWN, LEFT, RIGHT, START, SELECT, A_ACTION, B_ACTION, ESCAPE, SPACE, ENTER, LEFT_CLICK, RIGHT_CLICK };

	std::map<std::string, ButtonValue> easy_sdl2_Input_Map;

	double player_movement = 10.7;

	double diagonal_x = 0;
	double diagonal_y = 0;

	bool player_move_up, player_move_down, player_move_left, player_move_right;

public:
	Player();
	Player(double passed_x, double passed_y, double passed_w, double passed_h);

	~Player();
	void Draw(SDL_Renderer* passed_renderer);

	void SetGameEvent(SDL_Event* passed_event);

	void SetPlayerRect(double passed_x, double passed_y, double passed_w, double passed_h);
	void MovePlayerFigure(double passed_x, double passed_y);

	void LoadPlayerFigure(SDL_Renderer* passed_renderer);

	void PlayerEvent();

	void LoadInputMap();

	void Clean();

	void SetDiagonalMovement(double passed_c_side);

	//button stuff

	bool ButtonInputCheck(std::string input_to_check);
	bool ButtonReleasedCheck();
	bool ButtonPressedCheck();

};

#endif //PLAYER_H