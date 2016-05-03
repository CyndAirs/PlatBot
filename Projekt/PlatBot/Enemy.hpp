#ifndef ENEMY
#define ENEMY

#include <string>

#include "MobileObject.hpp"
#include "DamagableObject.hpp"

#include "GameManager.hpp"
#include "BGElement.hpp"
#include "Attack.hpp"
#include "Projectile.hpp"
#include "Hit.hpp"

class Enemy : public MobileObject, public DamagableObject
{
public:

	//Update'uje obiekt. WskaŸnik game wskazuje na grê, map zawiera planszê, attack zawiera wektor wskaŸników na ataki, do którego ewentualne nowe ataki maj¹ byæ przypisane, dt wskazuje ró¿nicê czasu.
	void update(GameManager * game, std::vector<std::deque<BGElement*>> &map, std::vector<Attack*> &attacks, const float time);

	//Sprawdza kolizjê obiektu z atakiem, je¿eli wyst¹pi³a, zadaje mu obra¿enia i zwraca true.
	bool checkHit(Attack * attack);

	//Zwraca true je¿eli obiekt jest poza plansz¹.
	bool isOutside();

	//Przemieszcza obiekt o x pikseli w prawo.
	void move(float x);

	//Konstruktor domyœlny
	Enemy(){};

	//Enemy(GameManager * game, float x, float y, int type)
	Enemy(GameManager * game, float x, float y, int type);

private:

	//Czas oczekiwania na kolejny atak przeciwnika.
	float cooldown;
};

#endif