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

	//Update'uje obiekt. Wska�nik game wskazuje na gr�, map zawiera plansz�, attack zawiera wektor wska�nik�w na ataki, do kt�rego ewentualne nowe ataki maj� by� przypisane, dt wskazuje r�nic� czasu.
	void update(GameManager * game, std::vector<std::deque<BGElement*>> &map, std::vector<Attack*> &attacks, const float time);

	//Sprawdza kolizj� obiektu z atakiem, je�eli wyst�pi�a, zadaje mu obra�enia i zwraca true.
	bool checkHit(Attack * attack);

	//Zwraca true je�eli obiekt jest poza plansz�.
	bool isOutside();

	//Przemieszcza obiekt o x pikseli w prawo.
	void move(float x);

	//Konstruktor domy�lny
	Enemy(){};

	//Enemy(GameManager * game, float x, float y, int type)
	Enemy(GameManager * game, float x, float y, int type);

private:

	//Czas oczekiwania na kolejny atak przeciwnika.
	float cooldown;
};

#endif