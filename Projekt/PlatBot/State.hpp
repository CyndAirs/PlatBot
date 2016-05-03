#pragma once
#include "GameManager.hpp"



class State
{
public:

	//Wska�nik na gr�.
	GameManager *game;

	//Rysuje stan w oknie.
	virtual void draw() = 0;

	//Od�wie�a stan. Parametr dt to r�nica czasu od ostatniego od�wie�enia.
	virtual void update(const float dt) = 0;

	//Sprawdza eventy.
	virtual void input() = 0;
};