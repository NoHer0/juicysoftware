#pragma once
#ifndef Map_h
#define Map_h

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>

class C_Map
{
private:
	sf::VertexArray m_kwadrat;
	sf::Texture m_tekstura;
	sf::RenderStates m_states;

	std::vector<float> m_map_data;

	float m_map, m_data;

public:
	void loadTextures();
	void loadMapFile();
	void renderMap(sf::RenderWindow * window);

};


#endif