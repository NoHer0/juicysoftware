#pragma once
#ifndef CollisionBlock_h
#define CollisionBlock_h

#include <SFML\Graphics.hpp>

class C_CollisionBlock
{
private:
	sf::RectangleShape m_collisionblock;
	sf::Vector2f m_size, m_position;
public:
	C_CollisionBlock(sf::Vector2f size, sf::Vector2f position);
	void render(sf::RenderWindow * window);

};

#endif