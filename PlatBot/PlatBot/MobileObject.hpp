#ifndef MOBILE_OBJECT
#define MOBILE_OBJECT

#include <string>

#include "Hitbox.hpp"
#include "GameManager.hpp"



class MobileObject
{
public:

	//Przemieszcza obiekt o d³ugoœæ jednego pola planszy.
	virtual void corrPos();

	//Zwraca Hitobox obiektu.
	Hitbox getHB();

	//Rysuje obiekt. WskaŸnik game wskazuje na grê.
	void draw(GameManager * game);

	//Konstruktor domyœnly.
	MobileObject(){};

	//Destruktor.
	~MobileObject(){};

protected:

	//Przechowuje teksturê.
	sf::Texture texture;

	//Hitbox obiektu.
	Hitbox hitbox;

	//Pozycja sprite'a obiektu (lewy górny róg)
	sf::Vector2f position;

	//Wymiary sprite'a obiektu.
	sf::Vector2i spriteSize;

	//Przyjmuje wartoœæ true je¿eli obiekt zwrócony jest w lewo.
	bool faceLeft;

	//Aktualna klatka animacji.
	int frame;

	//Typ obiektu. Pozwala na wykorzystywania tego samo kodu dla zró¿nicowanych obiektów.
	int type;
};

#endif