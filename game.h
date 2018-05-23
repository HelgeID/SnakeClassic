#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <thread>
#include <string>
#include "field.h"

#define text(name) # name

using namespace sf;

enum MODE { modeStop, modeUP, modeDown, modeLeft, modeRight };

struct Position
{
	int posX, posY;
};

class Game;

class Update
{
	void UpdateFUNC(Game&);
public:
	void operator()(Game& game)
	{
		UpdateFUNC(game);
	}
};

class Game
{
	Update updateObj;
	std::thread* thr;

	RenderWindow* window;
	Field* field;

	MODE mode;
	int lengthSnake;
	Position headSnake;

	void GetRandomCoordinatesHead(Position&); //used at the start

public:
	Game(RenderWindow&);
	~Game();

	std::vector<Position> snakeArr;

	void draw();
	void draw_snake(bool&);

	void key_pressed(Event&);

	//coordinates head
	Position TakeCoordinatesHead() { return{ headSnake.posX, headSnake.posY }; }
	void SetCoordinatesHead(int posX, int posY) { headSnake.posX = posX; headSnake.posY = posY; }

	//length Snake
	int TakeLengthSnake() { return lengthSnake; }
	void SetLengthSnake(int lengthSnake) { this->lengthSnake = lengthSnake; }

	//mode
	MODE TakeMODE() { return mode; }
	void SetMODE(MODE mode) { this->mode = mode; }

	//field
	Field* TakeField() { return field; }
};
