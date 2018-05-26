//File: source.cpp
//Author: HelgeID
//SFML SNAKE - FINAL
#include <SFML\Graphics.hpp>
#include "game.h"
#include <iostream>

using namespace sf;

#pragma comment (linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") //disable console

int main()
{
	std::cerr << "load games..." << std::endl;

	const std::string title = "Snake Classic, Score Food: 0";
	RenderWindow window(VideoMode(322, 322), title, Style::Close);
	window.setFramerateLimit(24);
	window.setVerticalSyncEnabled(true);
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
		//std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}

	return 0;
}
