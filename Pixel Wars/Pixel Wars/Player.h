#pragma once
#ifndef Player_h
#define Player_h

#include <SFML\Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "ResourceManager.h"

class C_Player : public C_Entity
{
private:

	float time;
	sf::Clock m_timer;
	
public:
	C_Player(sf::Vector2f size, sf::Vector2f pos);
	void update();
	void render(sf::RenderWindow * window);
};

#endif
