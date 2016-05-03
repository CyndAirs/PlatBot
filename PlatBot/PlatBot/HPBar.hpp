#ifndef HP_BAR
#define HP_BAR

#include "GameManager.hpp"
#include "Hitbox.hpp"

class HPBar
{
public:

	//Poprawia po�o�enie paska zycia na pos i rysuje pasek dla posta� kt�rej zosta�o size punkt�w �ycia, wska�nik game wskazuje na gr�.
	void draw(GameManager * game, sf::Vector2f pos, int size);

	//Konstruktor klasy. Parametry x, y to po�o�enie paska �ycia, wska�nik game wskazuje na gr�.
	HPBar(float x, float y, GameManager * game);

	//Konstrutor domy�lny
	HPBar(){};

private:

	//Pozycja paska �ycia.
	sf::Vector2f position;

	//Przechowuje tekstury.
	sf::Texture texture;

};

#endif