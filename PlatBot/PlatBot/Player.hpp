#ifndef PLAYER
#define PLAYER


#include <vector>
#include <deque>
#include <string>

#include "GameManager.hpp"
#include "MobileObject.hpp"
#include "DamagableObject.hpp"
#include "Attack.hpp"
#include "Projectile.hpp"
#include "Hit.hpp"
#include "BGElement.hpp"
#include "AnimationHandler.hpp"

class Player : public MobileObject, public DamagableObject
{
public:

	//Update'uje posta�, sprawdza input z klawiatury. Parametrami s� game, czyli wska�nik na gr�; map, czyli plansza; attacks, czyli vector atak�w, do kt�rego maj� by� dopisane ataki wykonane przez posta�; dt, czyli czas od ostatniego update'u.
	void update(GameManager * game, std::vector<std::deque<BGElement*>> &map, std::vector<Attack*> &attacks, const float dt);

	//Przemieszcza hitbox postaci po planszy. Parametr map to plansza, a x i y to warto�ci o jakie przesuwa si� posta�.
	void move(std::vector<std::deque<BGElement*>> &map, float x, float y);

	//Sprawdza kolizj� obiektu z atakiem, je�eli wyst�pi�a, zadaje mu obra�enia i zwraca true.
	bool checkHit(Attack * attack);

	//Ustawia pozycj� sprite'a.
	void fixPos();

	//Zwraca pozycj� sprite'a postaci (lewy g�rny r�g).
	sf::Vector2f GetPosition();

	//Konstruktor domy�lny.
	Player(){};

	//Konstruktor klasy. Parametr game to wska�nik na gr�, a parametry x i y to pozycja sprite'a postaci (lewy g�rny r�g).
	Player(GameManager * game, float x, float y);

	//Destruktor.
	~Player(){};

private:

	//Przyjmuje warto�� true gdy posta� stoi na pod�o�u.
	bool grounded;

	//Aktualne przy�pieszenie postaci w pionie.
	float acc;

	//Czas jaki musi min�� by posta� mog�a ponownie zaatakowa�.
	float cooldown;

	//Obiekt zajmuj�cy si� animacj�.
	AnimationHandler animation;
};

#endif