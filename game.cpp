#include "game.h"
#include <random>
#include <iostream>

//get random coordinates of head snake, when the game starts
void Game::GetRandomCoordinatesHead(Position& headSnake)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> RNDPOS(1, 4); //UP, DOWN, LEFT, RIGHT
	std::uniform_int_distribution<int> RNDCOORD(4, 27);

	int choice = RNDPOS(mt);
	std::string s_mode("");
	switch (choice)
	{
	case 1: headSnake.posX = RNDCOORD(mt); headSnake.posY = 4; mode = modeDown; s_mode = text(modeDown); break; //UP -> move DOWN
	case 2: headSnake.posX = RNDCOORD(mt); headSnake.posY = 27; mode = modeUP; s_mode = text(modeUP); break; //DOWN -> move UP
	case 3: headSnake.posX = 4; headSnake.posY = RNDCOORD(mt); mode = modeRight; s_mode = text(modeRight); break; //LEFT -> move RIGHT
	case 4: headSnake.posX = 27; headSnake.posY = RNDCOORD(mt); mode = modeLeft; s_mode = text(modeLeft); break; //RIGHT -> move LEFT

	default:
		headSnake.posX = 0;
		headSnake.posY = 0;
		mode = modeStop;
		break;
	}

	std::cerr << "get random coordinates of head snake: " << std::endl;
	std::cerr << "  head X: " << headSnake.posX << std::endl;
	std::cerr << "  head Y: " << headSnake.posY << std::endl;
	std::cerr << "  mode: " << s_mode << std::endl;
	return;
}

//constructor
Game::Game(RenderWindow& window)
{
	this->window = &window;
	field = new Field(SIZE, SIZE);
	GetRandomCoordinatesHead(headSnake);

	thr = new std::thread(updateObj, std::ref(*this));
	std::cerr << "a parallel thread is created (update): ok" << std::endl;
	thr->detach();

	std::cerr << std::endl << "object of the game is created: ok" << std::endl;
}

//destructor
Game::~Game()
{
	delete field;
	delete thr;
	std::cerr << "object of the game is removed: ok" << std::endl;
}

//draw field pixels
void Game::draw()
{
	static bool fDRAWSNAKE(false);
	for (int m(0); m < SIZE; ++m)
		for (int n(0); n < SIZE; ++n)
			window->draw(*field->field[n][m].pixel);

	if (!fDRAWSNAKE)
		this->draw_snake(fDRAWSNAKE);
}

//draw snake
void Game::draw_snake(bool& fDRAWSNAKE)
{
	snakeArr.push_back({ TakeCoordinatesHead().posX, TakeCoordinatesHead().posY });

	if (mode == modeUP) {
		snakeArr.push_back({ TakeCoordinatesHead().posX, TakeCoordinatesHead().posY + 1 });
		snakeArr.push_back({ TakeCoordinatesHead().posX, TakeCoordinatesHead().posY + 2 });
		snakeArr.push_back({ TakeCoordinatesHead().posX, TakeCoordinatesHead().posY + 3 });
	} else

	if (mode == modeDown) {
		snakeArr.push_back({ TakeCoordinatesHead().posX, TakeCoordinatesHead().posY - 1 });
		snakeArr.push_back({ TakeCoordinatesHead().posX, TakeCoordinatesHead().posY - 2 });
		snakeArr.push_back({ TakeCoordinatesHead().posX, TakeCoordinatesHead().posY - 3 });
	} else

	if (mode == modeLeft) {
		snakeArr.push_back({ TakeCoordinatesHead().posX + 1, TakeCoordinatesHead().posY });
		snakeArr.push_back({ TakeCoordinatesHead().posX + 2, TakeCoordinatesHead().posY });
		snakeArr.push_back({ TakeCoordinatesHead().posX + 3, TakeCoordinatesHead().posY });
	} else

	if (mode == modeRight) {
		snakeArr.push_back({ TakeCoordinatesHead().posX - 1, TakeCoordinatesHead().posY });
		snakeArr.push_back({ TakeCoordinatesHead().posX - 2, TakeCoordinatesHead().posY });
		snakeArr.push_back({ TakeCoordinatesHead().posX - 3, TakeCoordinatesHead().posY });
	}
	
	fDRAWSNAKE = true;

	for (Position item : snakeArr)
		field->field[item.posX][item.posY].SetPixel(BLUE);
	field->field[snakeArr[0].posX][snakeArr[0].posY].SetPixel(WHITE);

	SetLengthSnake(snakeArr.size());
	std::cerr << "draw a snake on a field of pixels: ok" << std::endl;
	return;
}

void Game::key_pressed(Event& event)
{
	if (event.key.code == sf::Keyboard::Up) {
		std::cerr << "\tkey is pressed: Up" << std::endl;
		this->SetMODE(modeUP);
		goto exit_point;
	}

	if (event.key.code == sf::Keyboard::Down) {
		std::cerr << "\tkey is pressed: Down" << std::endl;
		this->SetMODE(modeDown);
		goto exit_point;
	}

	if (event.key.code == sf::Keyboard::Right) {
		std::cerr << "\tkey is pressed: Right" << std::endl;
		this->SetMODE(modeRight);
		goto exit_point;
	}

	if (event.key.code == sf::Keyboard::Left) {
		std::cerr << "\tkey is pressed: Left" << std::endl;
		this->SetMODE(modeLeft);
		goto exit_point;
	}

exit_point:

	return;
}
