#include "pixel.h"

void Pixel::CreatePixel(int posX, int posY) {
	pixel = new sf::RectangleShape;
	this->pixel->setSize(sf::Vector2f(8, 8));
	this->pixel->setPosition(sf::Vector2f(posX, posY));
	this->pixel->setFillColor(sf::Color(42, 42, 42, 255));
	return;
}

void Pixel::DeletePixel()
{
	delete pixel;
	return;
}

void Pixel::SetPixel(COLOR color) {
	auto Color = [](COLOR color) {
		if (color == GRAY)
			return sf::Color(42, 42, 42, 255);
		else if (color == WHITE)
			return sf::Color(255, 255, 255, 255);
		else if (color == BLUE)
			return sf::Color(112, 146, 190, 255);
		else if (color == RED)
			return sf::Color(237, 28, 36, 255);
		else
			return sf::Color::Black;
	};
	this->pixel->setFillColor(Color(color));
	return;
}
