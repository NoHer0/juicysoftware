#include "Map.h"



void C_Map::renderMap(sf::RenderWindow * window)
{

	m_map = 0.f;

	for (float y = 0; y < 15; y++)
	{
		for (float x = 0; x < 20; x++)
		{
			m_kwadrat[0].position = sf::Vector2f(x * 32, y * 32);
			m_kwadrat[1].position = sf::Vector2f(x * 32 + 32, y * 32);
			m_kwadrat[2].position = sf::Vector2f(x * 32 + 32, y * 32 + 32);
			m_kwadrat[3].position = sf::Vector2f(x * 32, y * 32 + 32);

			m_kwadrat[0].texCoords = sf::Vector2f(0 + 32 * m_map_data[m_map] - 32, 0);
			m_kwadrat[1].texCoords = sf::Vector2f(32 + 32 * m_map_data[m_map] - 32, 0);
			m_kwadrat[2].texCoords = sf::Vector2f(32 + 32 * m_map_data[m_map] - 32, 32);
			m_kwadrat[3].texCoords = sf::Vector2f(0 + 32 * m_map_data[m_map] - 32, 32);
			m_map++;

			window->draw(m_kwadrat, m_states);
		}
	}

}

void C_Map::loadTextures()
{
	if (!(m_tekstura.loadFromFile("textures/map.png")))
	{
		std::cout << "map textures... ERROR" << std::endl;
	}
	else
	{
		std::cout << "map textures... OK" << std::endl;
		m_states.texture = &m_tekstura;

		m_kwadrat.setPrimitiveType(sf::Quads);
		m_kwadrat.resize(32);
	}
}

void C_Map::loadMapFile()
{
	std::ifstream map_file;
	map_file.open("maps/map01.txt");
	if ((!map_file.is_open())) std::cout << "map data... ERROR" << std::endl;
	else
	{
		std::cout << "map data... OK" << std::endl;
		while (map_file >> m_data)
		{ 
			m_map_data.push_back(m_data);
		}
	}
}