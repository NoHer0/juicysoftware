#include "Player.h"

C_Player::C_Player(sf::Vector2f size, sf::Vector2f pos) : C_Entity(size, pos)
{
	m_entity.setTexture(*ResourceManager::get()->getTexture("front.png"));
}

void C_Player::update()
{

	time = m_timer.restart().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_entity.setTexture(*ResourceManager::get()->getTexture("back.png"));
		m_factor = 200;
		m_angle = -90 * 2 * 3.14159 / 360;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_entity.setTexture(*ResourceManager::get()->getTexture("front.png"));
		m_factor = 200;
		m_angle = 90 * 2 * 3.14159 / 360;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_entity.setTexture(*ResourceManager::get()->getTexture("left.png"));
		m_factor = 200;
		m_angle = 180 * 2 * 3.14159 / 360;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_entity.setTexture(*ResourceManager::get()->getTexture("right.png"));
		m_factor = 200;
		m_angle = 0 * 2 * 3.14159 / 360;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		m_factor = 200;
		m_angle = -45 * 2 * 3.14159 / 360;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		m_factor = 200;
		m_angle = 45 * 2 * 3.14159 / 360;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		m_factor = 200;
		m_angle = -135 * 2 * 3.14159 / 360;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		m_factor = 200;
		m_angle = 135 * 2 * 3.14159 / 360;
	}





	m_entity.move(std::cos(m_angle) * m_factor * time, std::sin(m_angle) * m_factor * time);


	if (m_factor != 0) m_factor = 0;
}

void C_Player::render(sf::RenderWindow * window)
{
	window->draw(m_entity);
}