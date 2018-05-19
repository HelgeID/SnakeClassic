#pragma once

#include <SFML\Graphics.hpp>
#include "field.h"
using namespace sf;

enum MODE { modeStop, modeUP, modeDown, modeLeft, modeRight };

class Game
{
	RenderWindow* window;
	Field* field;

	MODE mode;

	struct Position
	{
		int posX, posY;
	};

	int lengthSnake;
	Position headSnake;

	void GetRandomCoordinatesHead(Position&); //used at the start

public:
	Game(RenderWindow&);
	~Game();

	void draw();
	void draw_snake();

	//Coordinates Head
	Position TakeCoordinatesHead() { return{ headSnake.posX, headSnake.posY }; }
	void SetCoordinatesHead(int posX, int posY) { headSnake.posX = posX; headSnake.posY = posY; }

	//Length Snake
	int TakeLengthSnake() { return lengthSnake; }
	void SetLengthSnake(int lengthSnake) { this->lengthSnake = lengthSnake; }

};
