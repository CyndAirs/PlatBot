#include "Hit.hpp"

//Konstruktor klasy. Zmienna game przechowuje wskaŸnik na grê, type to typ ataku, faceLeft informuje w któr¹ stronê wzglêdem postaci wykonany jest atak (true je¿eli w lewo), friendly informuje czy atak zosta³ wykonany przez gracza (true) czy przeciwnika (false), x i y to koordynaty po³o¿enia lewego górnego rogu hitboxa ataku.
Hit::Hit(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y) : Attack(game, type, faceLeft, friendly, x, y)
{
	timer = A_TIMER[type];
}

//Update'uje atak. map przechowuje planszê, dt przechowuje czas od ostatniego update'u.
void Hit::update(std::vector<std::deque<BGElement*>> &map, const float dt)
{
	timer -= dt;
}

//Sprawdza czy  czas trwania ataku zakoñczy³ siê, jeœli tak, zwraca true.
bool Hit::expired()
{
	if (timer <= 0) return true;
	else return false;
}
