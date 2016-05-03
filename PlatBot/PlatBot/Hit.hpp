#ifndef HIT
#define HIT

#include <vector>

#include "Attack.hpp"
#include "BGElement.hpp"
#include "GraphicsManager.hpp"

class Hit : public Attack
{
public:

	//Update'uje atak. map przechowuje plansz�, dt przechowuje czas od ostatniego update'u.
	void update(std::vector<std::deque<BGElement*>> &map, const float dt);

	//Sprawdza czy  czas trwania ataku zako�czy� si�, je�li tak, zwraca true.
	bool expired();

	//Konstruktor klasy. Zmienna game przechowuje wska�nik na gr�, type to typ ataku, faceLeft informuje w kt�r� stron� wzgl�dem postaci wykonany jest atak (true je�eli w lewo), friendly informuje czy atak zosta� wykonany przez gracza (true) czy przeciwnika (false), x i y to koordynaty po�o�enia lewego g�rnego rogu hitboxa ataku.
	Hit(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y);

	//Destruktor
	~Hit(){};

private:

	//Przechowuje pozosta�y czas trwania ataku.
	float timer;

};

#endif