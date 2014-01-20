#pragma once
#include <SFML/Graphics.hpp>

class ResourceManager
{
	private:
		sf::Texture m_playerTex;

		std::map<std::string, sf::Texture> m_textures;

		sf::Font m_font;

	public:
		static ResourceManager* get();

	public:
		ResourceManager(std::string filename);
		static ResourceManager* m_instance;

		sf::Texture* getTexture(std::string name){return &m_textures[name];}
		sf::Font* getFont(){return &m_font;}
};