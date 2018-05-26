//File: Update.cpp
//Author: HelgeID
#include "game.h"
#include <chrono>
#include <iostream>
#include <memory>

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

	bool food(false);
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		snakeArr = game.snakeArr;
		count = 0;
		for (Position &element : snakeArr) {
			if (element.posX == snakeArr[0].posX && element.posY == snakeArr[0].posY && !count) {
				if ((element.posX == game.TakeFood()->TakeCoordinatesFood().posX) && (element.posY == game.TakeFood()->TakeCoordinatesFood().posY))
					food = !food;

				try
				{
					bool next(false);
					for (Position &element_next : snakeArr) {
						if (next)
							element == element_next ?
								throw 0 : 0;
						else
							next = !next;
					}

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

					for (Position &element : game.snakeArr) {
						game.TakeField()->field[element.posX][element.posY].SetPixel(RED);
						std::cerr << " X:" << element.posX << " Y:" << element.posY << std::endl;
					}

					game.SetMODE(modeStop);
					game.TakeField()->field[game.TakeFood()->TakeCoordinatesFood().posX][game.TakeFood()->TakeCoordinatesFood().posY].SetPixel(GRAY);
					std::this_thread::sleep_for(std::chrono::seconds(1));

					game.TakeRW()->setTitle("Snake Classic, Game Over!");

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

		if (food)
		{
			int lengthSnake(game.TakeLengthSnake());
			std::auto_ptr<int> tailX(new int(snakeArr[lengthSnake - 1].posX));
			std::auto_ptr<int> tailY(new int(snakeArr[lengthSnake - 1].posY));
			game.snakeArr.push_back({ *tailX, *tailY });
			game.SetLengthSnake(lengthSnake + 1);
			game.UpdateFood();

			std::string score = std::to_string(game.TakeLengthSnake() - 4);
			game.TakeRW()->setTitle("Snake Classic, Score Food: " + score);

			food = !food;
		}
	}
exit:
	return;
}
