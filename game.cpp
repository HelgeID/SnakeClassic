#include "game.h"
#include <random>

//get random coordinates of head snake, when the game starts
void Game::GetRandomCoordinatesHead(Position& headSnake)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> RNDPOS(1, 4); //UP, DOWN, LEFT, RIGHT
	std::uniform_int_distribution<int> RNDCOORD(4, 27);

	int choice = RNDPOS(mt);

	switch (choice)
	{
	case 1: headSnake.posX = RNDCOORD(mt); headSnake.posY = 4; mode = modeDown; break;		//UP -> move DOWN
	case 2: headSnake.posX = RNDCOORD(mt); headSnake.posY = 27; mode = modeUP; break;		//DOWN -> move UP
	case 3: headSnake.posX = 4; headSnake.posY = RNDCOORD(mt); mode = modeRight; break;		//LEFT -> move RIGHT
	case 4: headSnake.posX = 27; headSnake.posY = RNDCOORD(mt); mode = modeLeft; break;		//RIGHT -> move LEFT

	default:
		headSnake.posX = 0;
		headSnake.posY = 0;
		mode = modeStop;
		break;
	}
	return;
}

//constructor
Game::Game(RenderWindow& window)
{
	this->window = &window;
	field = new Field(SIZE, SIZE);
	GetRandomCoordinatesHead(headSnake);
}

//destructor
Game::~Game()
{
	delete field;
}

//draw field pixels
void Game::draw()
{
	for (int m(0); m < SIZE; ++m)
		for (int n(0); n < SIZE; ++n)
			window->draw(*field->field[n][m].pixel);

	this->draw_snake();
}

//draw snake
void Game::draw_snake()
{
	field->field[TakeCoordinatesHead().posX][TakeCoordinatesHead().posY].SetPixel(WHITE);
	if (mode == modeUP) {
		field->field[TakeCoordinatesHead().posX][TakeCoordinatesHead().posY + 1].SetPixel(BLUE);
		field->field[TakeCoordinatesHead().posX][TakeCoordinatesHead().posY + 2].SetPixel(BLUE);
		field->field[TakeCoordinatesHead().posX][TakeCoordinatesHead().posY + 3].SetPixel(BLUE);
		return;
	}

	else if (mode == modeDown) {
		field->field[TakeCoordinatesHead().posX][TakeCoordinatesHead().posY - 1].SetPixel(BLUE);
		field->field[TakeCoordinatesHead().posX][TakeCoordinatesHead().posY - 2].SetPixel(BLUE);
		field->field[TakeCoordinatesHead().posX][TakeCoordinatesHead().posY - 3].SetPixel(BLUE);
		return;
	}

	else if (mode == modeLeft) {
		field->field[TakeCoordinatesHead().posX + 1][TakeCoordinatesHead().posY].SetPixel(BLUE);
		field->field[TakeCoordinatesHead().posX + 2][TakeCoordinatesHead().posY].SetPixel(BLUE);
		field->field[TakeCoordinatesHead().posX + 3][TakeCoordinatesHead().posY].SetPixel(BLUE);
		return;
	}

	else if (mode == modeRight) {
		field->field[TakeCoordinatesHead().posX - 1][TakeCoordinatesHead().posY].SetPixel(BLUE);
		field->field[TakeCoordinatesHead().posX - 2][TakeCoordinatesHead().posY].SetPixel(BLUE);
		field->field[TakeCoordinatesHead().posX - 3][TakeCoordinatesHead().posY].SetPixel(BLUE);
		return;
	}
}
