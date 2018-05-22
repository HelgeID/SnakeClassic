#include "game.h"
#include <chrono>
#include <iostream>

void Update::UpdateFUNC(Game& game)
{
	std::vector<Position> snakeArr;
	int count(0);

	std::this_thread::sleep_for(std::chrono::seconds(1));
	for (Position &element : game.snakeArr)
		game.TakeField()->field[element.posX][element.posY].SetPixel(WHITE);

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	for (Position &element : game.snakeArr)
		game.TakeField()->field[element.posX][element.posY].SetPixel(GRAY);

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		snakeArr = game.snakeArr;
		count = 0;
		for (Position &element : snakeArr) {
			if (element.posX == snakeArr[0].posX && element.posY == snakeArr[0].posY && !count) {
				if (game.TakeMODE() == modeUP) { game.snakeArr[count].posX = snakeArr[count].posX; game.snakeArr[count].posY = snakeArr[count].posY - 1; ++count; game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY - 1].SetPixel(WHITE); }
				else
				if (game.TakeMODE() == modeDown) { game.snakeArr[count].posX = snakeArr[count].posX; game.snakeArr[count].posY = snakeArr[count].posY + 1; ++count; game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY + 1].SetPixel(WHITE); }
				else
				if (game.TakeMODE() == modeLeft) { game.snakeArr[count].posX = snakeArr[count].posX - 1; game.snakeArr[count].posY = snakeArr[count].posY; ++count; game.TakeField()->field[game.snakeArr[count - 1].posX - 1][game.snakeArr[count - 1].posY].SetPixel(WHITE); }
				else
				if (game.TakeMODE() == modeRight) { game.snakeArr[count].posX = snakeArr[count].posX + 1; game.snakeArr[count].posY = snakeArr[count].posY; ++count; game.TakeField()->field[game.snakeArr[count - 1].posX + 1][game.snakeArr[count - 1].posY].SetPixel(WHITE); }
			}
			else {
				game.snakeArr[count].posX = snakeArr[count - 1].posX;
				game.snakeArr[count].posY = snakeArr[count - 1].posY;
				++count;
				if (game.TakeMODE() == modeUP) { game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY - 1].SetPixel(BLUE); game.SetCoordinatesHead(game.snakeArr[0].posX, game.snakeArr[0].posY - 1); }
				else
				if (game.TakeMODE() == modeDown) { game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY + 1].SetPixel(BLUE); game.SetCoordinatesHead(game.snakeArr[0].posX, game.snakeArr[0].posY + 1); }
				else
				if (game.TakeMODE() == modeLeft) { game.TakeField()->field[game.snakeArr[count - 1].posX - 1][game.snakeArr[count - 1].posY].SetPixel(BLUE); game.SetCoordinatesHead(game.snakeArr[0].posX - 1, game.snakeArr[0].posY); }
				else
				if (game.TakeMODE() == modeRight) { game.TakeField()->field[game.snakeArr[count - 1].posX + 1][game.snakeArr[count - 1].posY].SetPixel(BLUE); game.SetCoordinatesHead(game.snakeArr[0].posX + 1, game.snakeArr[0].posY); }
			}
		}
		game.TakeField()->field[snakeArr[game.TakeLengthSnake() - 2].posX][snakeArr[game.TakeLengthSnake() - 2].posY].SetPixel(GRAY);
	}
}
