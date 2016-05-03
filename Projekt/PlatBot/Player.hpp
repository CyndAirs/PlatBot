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

	//Update'uje postaæ, sprawdza input z klawiatury. Parametrami s¹ game, czyli wskaŸnik na grê; map, czyli plansza; attacks, czyli vector ataków, do którego maj¹ byæ dopisane ataki wykonane przez postaæ; dt, czyli czas od ostatniego update'u.
	void update(GameManager * game, std::vector<std::deque<BGElement*>> &map, std::vector<Attack*> &attacks, const float dt);

	//Przemieszcza hitbox postaci po planszy. Parametr map to plansza, a x i y to wartoœci o jakie przesuwa siê postaæ.
	void move(std::vector<std::deque<BGElement*>> &map, float x, float y);

	//Sprawdza kolizjê obiektu z atakiem, je¿eli wyst¹pi³a, zadaje mu obra¿enia i zwraca true.
	bool checkHit(Attack * attack);

	//Ustawia pozycjê sprite'a.
	void fixPos();

	//Zwraca pozycjê sprite'a postaci (lewy górny róg).
	sf::Vector2f GetPosition();

	//Konstruktor domyœlny.
	Player(){};

	//Konstruktor klasy. Parametr game to wskaŸnik na grê, a parametry x i y to pozycja sprite'a postaci (lewy górny róg).
	Player(GameManager * game, float x, float y);

	//Destruktor.
	~Player(){};

private:

	//Przyjmuje wartoœæ true gdy postaæ stoi na pod³o¿u.
	bool grounded;

	//Aktualne przyœpieszenie postaci w pionie.
	float acc;

	//Czas jaki musi min¹æ by postaæ mog³a ponownie zaatakowaæ.
	float cooldown;

	//Obiekt zajmuj¹cy siê animacj¹.
	AnimationHandler animation;
};

#endif