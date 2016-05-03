#include "GraphicsManager.hpp"

//£aduje tekstury.
void GraphicsManager::load()
{
	loadTexture("buttons", "images/buttons.png");

	loadTexture("tiles", "images/tiles.png");

	loadTexture("player", "images/player.png");

	loadTexture("enemies", "images/enemies.png");

	loadTexture("attacks", "images/attacks.png");

	loadTexture("hpbar", "images/hpbar.png");
}

//Dodaje do mapy textures teksturê o nazwie texturename z pliku filename.
void GraphicsManager::loadTexture(const std::string& texturename, const std::string& filename)
{	
	sf::Texture* texptr = new sf::Texture;

	if (!texptr->loadFromFile(filename))
	{
		//Wyjatek w wypadku gdy nie ma pliku z tekstur¹
		throw std::runtime_error("Missing file: " + filename);
	}

	textures[texturename] = texptr;
}

//Zwraca wskaŸnik na teksturê o nazwie name.
sf::Texture& GraphicsManager::getRef(const std::string& name)
{
	if (textures.count(name))
	{
		return *textures.at(name);
	}
	throw _exception();
}

//Konstruktor klasy. £aduje tekstury z plików.
GraphicsManager::GraphicsManager()
{
	load();
}

//Destruktor
GraphicsManager::~GraphicsManager()
{
	//Kasowanie tekstur
	for (std::map<std::string, sf::Texture*>::iterator it = textures.begin(); it != textures.end(); ++it)
	{
		delete it->second;
	}
	textures.clear();
}