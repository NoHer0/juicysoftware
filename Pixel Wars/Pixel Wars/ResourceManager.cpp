#include "ResourceManager.h"
ResourceManager* ResourceManager::m_instance = NULL;

ResourceManager::ResourceManager(std::string filename)
{
	m_textures["back.png"] = sf::Texture();
	m_textures["back.png"].loadFromFile("textures/back.png");
	
	m_textures["front.png"] = sf::Texture();
	m_textures["front.png"].loadFromFile("textures/front.png");
	
	m_textures["left.png"] = sf::Texture();
	m_textures["left.png"].loadFromFile("textures/left.png");
	
	m_textures["right.png"] = sf::Texture();
	m_textures["right.png"].loadFromFile("textures/right.png");
	
	m_textures["map.png"] = sf::Texture();
	m_textures["map.png"].loadFromFile("textures/map.png");
	m_textures["map.png"].setSmooth(true);
	
	m_font.loadFromFile("C:\\Windows\\Fonts\\consola.ttf");
}

ResourceManager* ResourceManager::get()
{
	if(m_instance == NULL) m_instance = new ResourceManager("textures/");
	return m_instance;
}