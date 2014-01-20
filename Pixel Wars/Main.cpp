#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML\Graphics.hpp>


#include "Entity.h"
#include "Map.h"

int main()
{
	// wysokosc, szerokosc, nazwa okna
	const unsigned short int appWidth = 640;
	const unsigned short int appHeight = 480;
	std::string appName = "Pixel Wars";

	// deklaracja okna
	sf::RenderWindow window(sf::VideoMode(appWidth, appHeight, 32), appName);
	window.setVerticalSyncEnabled(true);

	// nowy gracz na tibijskiej arenie
	C_Entity gracz(sf::Vector2f(42, 42), sf::Vector2f(0, 0));

	C_Map mapa;
	mapa.loadTextures();
	mapa.loadMapFile();
	


	//sf::Clock clock;
	//double FPS_counter;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
		}


		//FPS_counter = 1 / clock.restart().asSeconds();
		//std::cout << FPS_counter << std::endl;

		window.clear();

		mapa.renderMap(&window);
		gracz.checkCollision();
		gracz.updatePos();
		gracz.mouseClick();
		gracz.render(&window);
		window.display();
		//hehe
	}
	return 0;
}


