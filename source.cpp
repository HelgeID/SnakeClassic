//Test Pixel
#include "pixel.h"
#include <SFML\Graphics.hpp>

int main()
{
	using namespace sf;
	RenderWindow window(VideoMode(322, 322), "SFML SNAKE", Style::Close);

	Pixel pixel;
	pixel.CreatePixel(10, 10);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				//window.close();
				pixel.SetPixel(BLUE);
		}
		window.clear();
		window.draw(*pixel.pixel);
		window.display();
	}
	pixel.DeletePixel();//don't forget to clear the memory!!!
	return 0;
}
