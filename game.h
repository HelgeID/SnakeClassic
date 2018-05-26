//File: game.h
//Author: HelgeID
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <thread>
#include <string>
#include "field.h"
#include "food.h"

#define text(name) # name

using namespace sf;

enum MODE { modeStop, modeUP, modeDown, modeLeft, modeRight };

struct Position
{
	int posX, posY;
	bool operator== (const Position& obj) const
	{
		if (obj.posX == this->posX && obj.posY == this->posY)
			return true;
		return false;
	}
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
	FoodSnake::Food* food;

	MODE mode;
	int lengthSnake;
	Position headSnake;

	void GetRandomCoordinatesHead(Position&); //used at the start
	void RandomFoodPosition(int&, int&);

public:
	Game(RenderWindow&);
	~Game();

	std::vector<Position> snakeArr;

	void draw();
	void draw_snake(bool&);
	void draw_frame(bool&);

	void key_pressed(Event&);

	//coordinates head
	Position TakeCoordinatesHead() { return{ headSnake.posX, headSnake.posY }; }
	void SetCoordinatesHead(int posX, int posY) { headSnake.posX = posX; headSnake.posY = posY; }

	//length snake
	int TakeLengthSnake() { return lengthSnake; }
	void SetLengthSnake(int lengthSnake) { this->lengthSnake = lengthSnake; }

	//mode
	MODE TakeMODE() { return mode; }
	void SetMODE(MODE mode) { this->mode = mode; }

	//field
	Field* TakeField() { return field; }

	//food
	void UpdateFood();
	FoodSnake::Food* TakeFood() { return food; }

	//window
	RenderWindow* TakeRW() { return window; }
};
