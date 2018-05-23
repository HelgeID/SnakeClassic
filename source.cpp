//Test control and move
#include <SFML\Graphics.hpp>
#include "game.h"
#include <iostream>
using namespace sf;

int main()
{
	std::cerr << "load games..." << std::endl;
	RenderWindow window(VideoMode(322, 322), "SFML SNAKE", Style::Close);
	Game game(window);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed)
				game.key_pressed(event);
		}
		window.clear();
		game.draw();
		window.display();
	}

	return 0;
}
