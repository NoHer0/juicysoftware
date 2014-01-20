#include "Entity.h"

void C_Entity::render(sf::RenderWindow * window)
{
	window->draw(m_entity);
}

C_Entity::C_Entity(sf::Vector2f size, sf::Vector2f pos)
{
	m_entity_size = size,
	m_entity_pos = pos;

	m_entity.setSize(size);
	m_entity.setPosition(pos);
		
}


