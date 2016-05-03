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

	//Update menu (puste, bo menu nie ma elementów zale¿nych od czasu)
	virtual void update(const float dt){};
	
	//Sprawdza akcje myszki.
	virtual void input();

	//Konstruktor menu, game jest wskaŸnikiem na grê, retry==true je¿eli menu ma ukazaæ siê w formie retry po przegranej grze.
	Menu(GameManager* game, bool retry);

	//Destruktor
	~Menu();

private:

	//Rozpoczyna grê.
	void start();

	//Zmienia menu z wersji normalnej na wersjê wyœwietlaj¹c¹ siê po przegranej.
	bool retry;

	//Widok menu.
	sf::View menuView;

	//Przechowuje przyciski.
	std::vector<Button*> buttons;

};

#endif