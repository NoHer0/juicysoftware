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

	if (m_entityTexture_front.loadFromFile("textures/front.png") &&
		(m_entityTexture_back.loadFromFile("textures/back.png") &&
		(m_entityTexture_left.loadFromFile("textures/left.png") &&
		(m_entityTexture_right.loadFromFile("textures/right.png")))))
		{
		std::cout << "entity textures... OK" << std::endl;
		}
	m_entity.setTexture(&m_entityTexture_front);
}

void C_Entity::updatePos()
{

	time = m_timer.restart().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_entity.setTexture(&m_entityTexture_back);
		m_factor = 200;
		m_angle = -90 * 2 * 3.14159 / 360;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_entity.setTexture(&m_entityTexture_front);
		m_factor = 200;
		m_angle = 90 * 2 * 3.14159 / 360;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_entity.setTexture(&m_entityTexture_left);
		m_factor = 200;
		m_angle = 180 * 2 * 3.14159 / 360;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_entity.setTexture(&m_entityTexture_right);
		m_factor = 200;
		m_angle = 0 * 2 * 3.14159 / 360;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		m_entity.setTexture(&m_entityTexture_right);
		m_factor = 200;
		m_angle = -45 * 2 * 3.14159 / 360;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		m_entity.setTexture(&m_entityTexture_front);
		m_factor = 200;
		m_angle = 45 * 2 * 3.14159 / 360;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		m_entity.setTexture(&m_entityTexture_back);
		m_factor = 200;
		m_angle = -135 * 2 * 3.14159 / 360;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		m_entity.setTexture(&m_entityTexture_left);
		m_factor = 200;
		m_angle = 135 * 2 * 3.14159 / 360;
	}


	


	m_entity.move(std::cos(m_angle) * m_factor * time, std::sin(m_angle) * m_factor * time);


	if (m_factor != 0) m_factor = 0;
}

void C_Entity::mouseClick()
{
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) std::cout << sf::Mouse::getPosition().x;
}

void C_Entity::checkCollision()
{
	
}