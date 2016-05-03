#ifndef MOBILE_OBJECT
#define MOBILE_OBJECT

#include <string>

#include "Hitbox.hpp"
#include "GameManager.hpp"



class MobileObject
{
public:

	//Przemieszcza obiekt o d�ugo�� jednego pola planszy.
	virtual void corrPos();

	//Zwraca Hitobox obiektu.
	Hitbox getHB();

	//Rysuje obiekt. Wska�nik game wskazuje na gr�.
	void draw(GameManager * game);

	//Konstruktor domy�nly.
	MobileObject(){};

	//Destruktor.
	~MobileObject(){};

protected:

	//Przechowuje tekstur�.
	sf::Texture texture;

	//Hitbox obiektu.
	Hitbox hitbox;

	//Pozycja sprite'a obiektu (lewy g�rny r�g)
	sf::Vector2f position;

	//Wymiary sprite'a obiektu.
	sf::Vector2i spriteSize;

	//Przyjmuje warto�� true je�eli obiekt zwr�cony jest w lewo.
	bool faceLeft;

	//Aktualna klatka animacji.
	int frame;

	//Typ obiektu. Pozwala na wykorzystywania tego samo kodu dla zr�nicowanych obiekt�w.
	int type;
};

#endif