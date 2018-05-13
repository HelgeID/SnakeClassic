#pragma once

#include <SFML\Graphics.hpp>
#include "field.h"
using namespace sf;

class Game
{
	RenderWindow* window;
	Field* field;

public:
	Game(RenderWindow&);
	~Game();

	void draw();
};
