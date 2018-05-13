#include "game.h"

Game::Game(RenderWindow& window)
{
	this->window = &window;
	field = new Field(SIZE, SIZE);
}

Game::~Game()
{
	delete field;
}

void Game::draw()
{
	for (int m(0); m < SIZE; ++m)
		for (int n(0); n < SIZE; ++n)
			window->draw(*field->field[n][m].pixel);
}
