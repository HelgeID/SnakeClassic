//File: food.h
//Author: HelgeID
#pragma once

namespace FoodSnake
{
	struct Position
	{
		int posX, posY;
	};

	class Food
	{
	private:
		Position foodSnake;

	public:
		Food();
		Food(int, int);
		~Food();

		//coordinates food
		Position TakeCoordinatesFood() { return{ foodSnake.posX, foodSnake.posY }; }
		void SetCoordinatesFood(int posX, int posY) { foodSnake.posX = posX; foodSnake.posY = posY; }
	};
}
