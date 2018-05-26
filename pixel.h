//File: pixel.h
//Author: HelgeID
#pragma once
#include <SFML\Graphics.hpp>

enum COLOR { GRAY, WHITE, BLUE,  RED, LIGHT_GRAY};

struct Pixel {
	sf::RectangleShape* pixel;
	void CreatePixel(int, int);//arg: position x, position y
	void DeletePixel();
	void SetPixel(COLOR);
};
