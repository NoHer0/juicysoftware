#pragma once
#ifndef Entity_h
#define Entity_h

#include <SFML\Graphics.hpp>
#include <iostream>

#include "ResourceManager.h"


class C_Entity
{
protected:
	sf::Vector2f m_entity_size, m_entity_pos;
	float m_factor, m_angle;
	float time;
	sf::RectangleShape m_entity;
	sf::Clock m_timer;
public:
	C_Entity(sf::Vector2f size, sf::Vector2f pos);
	virtual void update() = 0;
	virtual void render(sf::RenderWindow * window);
};


#endif