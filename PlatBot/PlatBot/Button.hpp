#ifndef BUTTON
#define BUTTON

#pragma once

#include <string>
#include "GameManager.hpp"
#include "Hitbox.hpp"

enum ButtonAction
{
	Start, Exit, Retry
};

class Button
{
public:

	//Zwraca true gdy punkt mpos znajduje si� wewn�trz przycisku.
	bool CheckCollision(sf::Vector2f mpos);

	//Rysuje przycisk. Wska�nik game wskazuje na gr�.
	void draw(GameManager * game);

	//Konstruktor przycisku. Prametrami s�: action - akcja przycisku, texname - nazwa tekstury oraz game - wska�nik na gr�.
	Button(ButtonAction action, const std::string & texname, GameManager * game);

	//Zwraca akcj� przycisku.
	const ButtonAction ActionName();

private:

	//Pozycja tekstury w oknie.
	sf::Vector2i texpos;

	//Hitbox przycisku.
	Hitbox hitbox;

	//Pozycja pola na planszy (w pikselach).
	sf::Texture texture;

	//Przechowuje tekstur�.
	ButtonAction action;

};

#endif