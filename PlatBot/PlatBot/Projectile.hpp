#ifndef PROJECTILE
#define PROJECTILE

#include <vector>

#include "Attack.hpp"
#include "BGElement.hpp"
#include "GraphicsManager.hpp"

class Projectile : public Attack
{
public:

	//Update'uje atak. map przechowuje planszê, dt przechowuje czas od ostatniego update'u.
	void update(std::vector<std::deque<BGElement*>> &map, const float dt);

	//Przemieszcza obiekt o x pikseli w lewo.
	void move(float x);

	//Konstruktor klasy. Zmienna game przechowuje wskaŸnik na grê, type to typ ataku, faceLeft informuje w któr¹ stronê wzglêdem postaci wykonany jest atak (true je¿eli w lewo), friendly informuje czy atak zosta³ wykonany przez gracza (true) czy przeciwnika (false), x i y to koordynaty po³o¿enia lewego górnego rogu hitboxa ataku, speed to prêdkoœæ poruszania siê ataku.
	Projectile(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y, int speed);

private:

	//Prêdkoœæ przemieszczania siê pocisku.
	int speed;

};

#endif