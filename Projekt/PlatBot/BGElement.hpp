#ifndef BGELEMENT
#define BGELEMENT

#include <string>

#include "Hitbox.hpp"
#include "GameManager.hpp"

enum BgId
{ 
	Blank, StartBlock, MiddleBlock, EndBlock
};


class BGElement
{
public:

	//Zwraca Hitbox pola planszy.
	Hitbox checkHB();

	//Rysuje pole planszy. Wska�nik game wskazuje na gr�.
	void draw(GameManager* game);

	//Zwraca rodzaj pola planszy.
	BgId checkID();

	//Domyslny konstruktor. Nadaje polu planszy Id = 0;
	BGElement();

	//Konstruktor pola planszy. Wska�nik game wskazuje na gr�. id zawiera rodzaj pola, cox, coy to koordynaty na mapie planszy (w polach).
	BGElement(GameManager* game, BgId id, int cox, int coy);

	//Destruktor
	~BGElement(){};

protected:

	//Hitbox pola planszy.
	Hitbox hitbox;

	//Rodzaj pola planszy.
	BgId id;

	//Pozycja pola na planszy(w pikselach).
	sf::Vector2i pos;

	//Przechowuje tekstur�.
	sf::Texture texture;

};

#endif