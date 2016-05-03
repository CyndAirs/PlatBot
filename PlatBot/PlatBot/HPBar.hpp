#ifndef HP_BAR
#define HP_BAR

#include "GameManager.hpp"
#include "Hitbox.hpp"

class HPBar
{
public:

	//Poprawia po³o¿enie paska zycia na pos i rysuje pasek dla postaæ której zosta³o size punktów ¿ycia, wskaŸnik game wskazuje na grê.
	void draw(GameManager * game, sf::Vector2f pos, int size);

	//Konstruktor klasy. Parametry x, y to po³o¿enie paska ¿ycia, wskaŸnik game wskazuje na grê.
	HPBar(float x, float y, GameManager * game);

	//Konstrutor domyœlny
	HPBar(){};

private:

	//Pozycja paska ¿ycia.
	sf::Vector2f position;

	//Przechowuje tekstury.
	sf::Texture texture;

};

#endif