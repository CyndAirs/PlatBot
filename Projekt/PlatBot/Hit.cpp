#include "Hit.hpp"

//Konstruktor klasy. Zmienna game przechowuje wska�nik na gr�, type to typ ataku, faceLeft informuje w kt�r� stron� wzgl�dem postaci wykonany jest atak (true je�eli w lewo), friendly informuje czy atak zosta� wykonany przez gracza (true) czy przeciwnika (false), x i y to koordynaty po�o�enia lewego g�rnego rogu hitboxa ataku.
Hit::Hit(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y) : Attack(game, type, faceLeft, friendly, x, y)
{
	timer = A_TIMER[type];
}

//Update'uje atak. map przechowuje plansz�, dt przechowuje czas od ostatniego update'u.
void Hit::update(std::vector<std::deque<BGElement*>> &map, const float dt)
{
	timer -= dt;
}

//Sprawdza czy  czas trwania ataku zako�czy� si�, je�li tak, zwraca true.
bool Hit::expired()
{
	if (timer <= 0) return true;
	else return false;
}
