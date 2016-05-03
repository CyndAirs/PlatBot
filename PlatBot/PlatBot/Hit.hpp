#ifndef HIT
#define HIT

#include <vector>

#include "Attack.hpp"
#include "BGElement.hpp"
#include "GraphicsManager.hpp"

class Hit : public Attack
{
public:

	//Update'uje atak. map przechowuje planszê, dt przechowuje czas od ostatniego update'u.
	void update(std::vector<std::deque<BGElement*>> &map, const float dt);

	//Sprawdza czy  czas trwania ataku zakoñczy³ siê, jeœli tak, zwraca true.
	bool expired();

	//Konstruktor klasy. Zmienna game przechowuje wskaŸnik na grê, type to typ ataku, faceLeft informuje w któr¹ stronê wzglêdem postaci wykonany jest atak (true je¿eli w lewo), friendly informuje czy atak zosta³ wykonany przez gracza (true) czy przeciwnika (false), x i y to koordynaty po³o¿enia lewego górnego rogu hitboxa ataku.
	Hit(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y);

	//Destruktor
	~Hit(){};

private:

	//Przechowuje pozosta³y czas trwania ataku.
	float timer;

};

#endif