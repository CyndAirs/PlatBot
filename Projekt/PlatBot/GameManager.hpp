#pragma once

#include <deque>
#include <SFML\Graphics.hpp>
#include "GraphicsManager.hpp"
#include "Constants.h"

class State;

class GameManager
{
public:

	//Okno gry.
	sf::RenderWindow window;

	//Tekstury.
	GraphicsManager textures;


	//Umieszcza na stosie obiekt klasy State wskazywany przez wska�nik state.
	void pushState(State* state);

	//Usuwa obiekt na szczycie stosu states je�eli stos nie jest pusty.
	void popState();

	//Zwraca wska�nik na obiekt na szczycie stosu states. Je�eli stos jest pusty zwraca nullptr.
	State* checkState();

	// Petla g��wna gry.
	void loop();

	//Konstrutor klasy, tworzy okno gry.
	GameManager();

	//Destruktor
	~GameManager();

private:

	//Przechowuje stany gry.
	std::deque<State*> states;
};

