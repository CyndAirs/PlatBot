#ifndef ATTACK
#define ATTACK

#include "MobileObject.hpp"
#include "BGElement.hpp"
#include "GraphicsManager.hpp"


class Attack : public MobileObject
{
public:

	//Czysto wirtualna metoda wykorzystywana przez klasy potomne do update'owania. Zmienna map przechowuje plan planszy (patrz map w klasie Level), time przechowuje czas od ostatniego update'u.
	virtual void update(std::vector<std::deque<BGElement*>> &map, const float dt) = 0;

	//Sprawdza czy Atatck znajduje si� poza plansz�.Je�eli tak, zwraca true.
	bool isOutside();

	//Sprawdza czy atak zosta� wykonany przez gracza (zwraca true) czy przeciwnika.(zwraca false)
	bool checkFriendly();

	//Konstruktor klasy. Zmienna game przechowuje wska�nik na gr�, type to typ ataku, faceLeft informuje w kt�r� stron� wzgl�dem postaci wykonany jest atak(true je�eli w lewo), friendly informuje czy atak zosta� wykonany przez gracza(true) czy przeciwnika(false), x i y to koordynaty po�o�enia lewego g�rnego rogu hitboxa ataku.
	Attack(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y);

	//Destruktor
	~Attack(){};

protected:

	//Informacja czy atak zosta� wykonany przez gracza czy przeciwnika.
	bool isFriendly;

};

#endif