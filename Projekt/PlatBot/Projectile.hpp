#ifndef PROJECTILE
#define PROJECTILE

#include <vector>

#include "Attack.hpp"
#include "BGElement.hpp"
#include "GraphicsManager.hpp"

class Projectile : public Attack
{
public:

	//Update'uje atak. map przechowuje plansz�, dt przechowuje czas od ostatniego update'u.
	void update(std::vector<std::deque<BGElement*>> &map, const float dt);

	//Przemieszcza obiekt o x pikseli w lewo.
	void move(float x);

	//Konstruktor klasy. Zmienna game przechowuje wska�nik na gr�, type to typ ataku, faceLeft informuje w kt�r� stron� wzgl�dem postaci wykonany jest atak (true je�eli w lewo), friendly informuje czy atak zosta� wykonany przez gracza (true) czy przeciwnika (false), x i y to koordynaty po�o�enia lewego g�rnego rogu hitboxa ataku, speed to pr�dko�� poruszania si� ataku.
	Projectile(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y, int speed);

private:

	//Pr�dko�� przemieszczania si� pocisku.
	int speed;

};

#endif