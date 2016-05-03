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

	//Rysuje planszê. 
	virtual void draw();

	//Update'uje plansze, dt to czas od ostatniego update'u.
	virtual void update(const float dt);

	//Sprawdza czy okno zosta³o zamkniête.
	virtual void input();

	//Konstruktor klasy. Parametr game wskazuje na grê.
	Level(GameManager* game);

	//Destruktor.
	~Level();

private:

	//Prze³¹cza na stan Menu z wartoœci¹ retry=true w razie przegranej.
	void retry();

	//Generuje now¹ kolumnê plany planszy algorytmem i umieszcza j¹ na koñcu defmap. Usuwa pierwsz¹ kolumnê defmap.
	void generate();

	//Odœwie¿a map generuj¹c j¹ jeszcze raz na podstawie defmap.
	void genMap();

	//Generuje przeciwnika typu type na polu planszy odpowiadaj¹cym koordynatom x, y (w polach) na planie planszy.
	void spawn(int x, int y, int type);

	//Widok poziomu.
	sf::View levelView;

	//Plan planszy.
	std::vector<std::deque<int>> defmap;

	//Plansza.
	std::vector<std::deque<BGElement*>> map;

	//Postaæ gracza.
	Player playchar;

	//Przeciwnicy.
	std::vector<Enemy*> enemies;

	//Aktywne ataki.
	std::vector<Attack*> attacks;

	//Interface paska ¿ycia.
	HPBar hpbar;

	//Interface paska punktacji.
	ScoreBar scorebar;

	//Aktualna iloœæ punktów.
	int points;

	
};

#endif