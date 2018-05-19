#include "field.h"

Field::Field(const int mSize, const int nSize)
{
	//don't to change
	const int start_position(2);
	const int step_position(10);

	Pixel pixel;
	std::vector<std::vector<Pixel>> field(mSize, std::vector<Pixel>(nSize, pixel));
	this->field = field;

	//create field of the pixels
	int posX(start_position), posY(start_position);
	for (int m(0); m < SIZE; ++m) {
		for (int n(0); n < SIZE; ++n) {
			this->field[n][m].CreatePixel(posX, posY);
			posX += step_position;
		}
		posY += step_position;
		posX = start_position;
	}
}

Field::~Field()
{
	for (int m(0); m < SIZE; ++m)
		for (int n(0); n < SIZE; ++n)
			this->field[n][m].DeletePixel();
}
