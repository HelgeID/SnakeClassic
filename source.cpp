//Test Field
#include <SFML\Graphics.hpp>
#include "game.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(322, 322), "SFML SNAKE", Style::Close);
	Game game(window);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		game.draw();
		window.display();
	}
	return 0;
}
