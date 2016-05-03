#pragma once
#include "GameManager.hpp"



class State
{
public:

	//WskaŸnik na grê.
	GameManager *game;

	//Rysuje stan w oknie.
	virtual void draw() = 0;

	//Odœwie¿a stan. Parametr dt to ró¿nica czasu od ostatniego odœwie¿enia.
	virtual void update(const float dt) = 0;

	//Sprawdza eventy.
	virtual void input() = 0;
};