#pragma once
#ifndef Entity_h
#define Entity_h

#include <SFML\Graphics.hpp>
#include <iostream>

class C_Entity
{
private:
	sf::Vector2f m_entity_size, m_entity_pos;
	float m_factor, m_angle;
	float time;
	sf::RectangleShape m_entity;
	sf::Texture m_entityTexture_front, m_entityTexture_back, m_entityTexture_left, m_entityTexture_right;
	sf::Clock m_timer;
public:
	C_Entity(sf::Vector2f size, sf::Vector2f pos);
	void updatePos();
	void mouseClick();
	void checkCollision();
	void render(sf::RenderWindow * window);
};


#endif