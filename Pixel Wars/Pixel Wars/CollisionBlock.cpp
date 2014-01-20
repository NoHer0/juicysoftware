#include "CollisionBlock.h"

C_CollisionBlock::C_CollisionBlock(sf::Vector2f size, sf::Vector2f position)
{
	m_size = size;
	m_position = position;

	m_collisionblock.setFillColor(sf::Color(255,0,0,150));
	m_collisionblock.setSize(size);
	m_collisionblock.setPosition(position);
}

void C_CollisionBlock::render(sf::RenderWindow * window)
{
	window->draw(m_collisionblock);
}