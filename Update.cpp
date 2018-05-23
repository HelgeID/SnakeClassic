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
				try
				{
					game.snakeArr[count].posX == SIZE - 1 || game.snakeArr[count].posX == 0 || game.snakeArr[count].posY == SIZE - 1 || game.snakeArr[count].posY == 0 ?
						throw 0 : 0;

					if (game.TakeMODE() == modeUP) { game.snakeArr[count].posX = snakeArr[count].posX; game.snakeArr[count].posY = snakeArr[count].posY - 1; ++count; game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY].SetPixel(WHITE); }
					else
					if (game.TakeMODE() == modeDown) { game.snakeArr[count].posX = snakeArr[count].posX; game.snakeArr[count].posY = snakeArr[count].posY + 1; ++count; game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY].SetPixel(WHITE); }
					else
					if (game.TakeMODE() == modeLeft) { game.snakeArr[count].posX = snakeArr[count].posX - 1; game.snakeArr[count].posY = snakeArr[count].posY; ++count; game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY].SetPixel(WHITE); }
					else
					if (game.TakeMODE() == modeRight) { game.snakeArr[count].posX = snakeArr[count].posX + 1; game.snakeArr[count].posY = snakeArr[count].posY; ++count; game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY].SetPixel(WHITE); }
				}

				catch (...)
				{
					std::cout << "BOOM!" << std::endl;

					for (Position &element : game.snakeArr)
						std::cout << element.posX << " " << element.posY << std::endl;

					game.SetMODE(modeStop);
					std::this_thread::sleep_for(std::chrono::seconds(1));
					goto exit;
				}
			}
			else {
				game.snakeArr[count].posX = snakeArr[count - 1].posX;
				game.snakeArr[count].posY = snakeArr[count - 1].posY;
				++count;
				if (game.TakeMODE() == modeUP) { game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY].SetPixel(BLUE); game.SetCoordinatesHead(game.snakeArr[0].posX, game.snakeArr[0].posY - 1); }
				else
				if (game.TakeMODE() == modeDown) { game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY].SetPixel(BLUE); game.SetCoordinatesHead(game.snakeArr[0].posX, game.snakeArr[0].posY + 1); }
				else
				if (game.TakeMODE() == modeLeft) { game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY].SetPixel(BLUE); game.SetCoordinatesHead(game.snakeArr[0].posX - 1, game.snakeArr[0].posY); }
				else
				if (game.TakeMODE() == modeRight) { game.TakeField()->field[game.snakeArr[count - 1].posX][game.snakeArr[count - 1].posY].SetPixel(BLUE); game.SetCoordinatesHead(game.snakeArr[0].posX + 1, game.snakeArr[0].posY); }
			}
		}
		game.TakeField()->field[snakeArr[game.TakeLengthSnake() - 1].posX][snakeArr[game.TakeLengthSnake() - 1].posY].SetPixel(GRAY);
	}
exit:
	return;
}
