#ifndef MENU
#define MENU

#pragma once

#include <vector>

#include <SFML\Graphics.hpp>

#include "State.hpp"
#include "Button.hpp"

class Menu : public State
{
public:

	//Rysuje menu.
	virtual void draw();

	//Update menu (puste, bo menu nie ma element�w zale�nych od czasu)
	virtual void update(const float dt){};
	
	//Sprawdza akcje myszki.
	virtual void input();

	//Konstruktor menu, game jest wska�nikiem na gr�, retry==true je�eli menu ma ukaza� si� w formie retry po przegranej grze.
	Menu(GameManager* game, bool retry);

	//Destruktor
	~Menu();

private:

	//Rozpoczyna gr�.
	void start();

	//Zmienia menu z wersji normalnej na wersj� wy�wietlaj�c� si� po przegranej.
	bool retry;

	//Widok menu.
	sf::View menuView;

	//Przechowuje przyciski.
	std::vector<Button*> buttons;

};

#endif