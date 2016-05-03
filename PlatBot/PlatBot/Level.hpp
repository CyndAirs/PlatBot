#ifndef LEVEL
#define LEVEL

#pragma once

#include <vector>
#include <deque>
#include <algorithm>
#include <SFML\Graphics.hpp>
#include <random>
#include <functional>
#include <typeinfo>

#include "State.hpp"
#include "Menu.hpp"
#include "MobileObject.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Attack.hpp"
#include "Projectile.hpp"
#include "Hit.hpp"
#include "ScoreBar.hpp"
#include "HPBar.hpp"

class Level : public State
{
public:

	//Rysuje plansz�. 
	virtual void draw();

	//Update'uje plansze, dt to czas od ostatniego update'u.
	virtual void update(const float dt);

	//Sprawdza czy okno zosta�o zamkni�te.
	virtual void input();

	//Konstruktor klasy. Parametr game wskazuje na gr�.
	Level(GameManager* game);

	//Destruktor.
	~Level();

private:

	//Prze��cza na stan Menu z warto�ci� retry=true w razie przegranej.
	void retry();

	//Generuje now� kolumn� plany planszy algorytmem i umieszcza j� na ko�cu defmap. Usuwa pierwsz� kolumn� defmap.
	void generate();

	//Od�wie�a map generuj�c j� jeszcze raz na podstawie defmap.
	void genMap();

	//Generuje przeciwnika typu type na polu planszy odpowiadaj�cym koordynatom x, y (w polach) na planie planszy.
	void spawn(int x, int y, int type);

	//Widok poziomu.
	sf::View levelView;

	//Plan planszy.
	std::vector<std::deque<int>> defmap;

	//Plansza.
	std::vector<std::deque<BGElement*>> map;

	//Posta� gracza.
	Player playchar;

	//Przeciwnicy.
	std::vector<Enemy*> enemies;

	//Aktywne ataki.
	std::vector<Attack*> attacks;

	//Interface paska �ycia.
	HPBar hpbar;

	//Interface paska punktacji.
	ScoreBar scorebar;

	//Aktualna ilo�� punkt�w.
	int points;

	
};

#endif