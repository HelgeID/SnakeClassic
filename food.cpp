//File: food.cpp
//Author: HelgeID
#include "food.h"

FoodSnake::Food::Food()
{
}

FoodSnake::Food::Food(int posX, int posY)
{
	foodSnake.posX = posX;
	foodSnake.posY = posY;
}

FoodSnake::Food::~Food()
{
}
