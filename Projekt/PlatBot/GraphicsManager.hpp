#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class GraphicsManager
{

public:
	
	//£aduje tekstury.
	void load();

	//Dodaje do mapy textures teksturê o nazwie texturename z pliku filename.
	void loadTexture(const std::string& texturename, const std::string &filename);

	//Zwraca wskaŸnik na teksturê o nazwie name.
	sf::Texture& getRef(const std::string& name);

	//Konstruktor klasy. £aduje tekstury z plików.
	GraphicsManager();

	//Destruktor
	~GraphicsManager();

private:

	//Przechowuje tekstury sortowane nazwami.
	std::map<std::string, sf::Texture*> textures;
};