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

	//Zwraca true gdy punkt mpos znajduje siê wewn¹trz przycisku.
	bool CheckCollision(sf::Vector2f mpos);

	//Rysuje przycisk. WskaŸnik game wskazuje na grê.
	void draw(GameManager * game);

	//Konstruktor przycisku. Prametrami s¹: action - akcja przycisku, texname - nazwa tekstury oraz game - wskaŸnik na grê.
	Button(ButtonAction action, const std::string & texname, GameManager * game);

	//Zwraca akcjê przycisku.
	const ButtonAction ActionName();

private:

	//Pozycja tekstury w oknie.
	sf::Vector2i texpos;

	//Hitbox przycisku.
	Hitbox hitbox;

	//Pozycja pola na planszy (w pikselach).
	sf::Texture texture;

	//Przechowuje teksturê.
	ButtonAction action;

};

#endif