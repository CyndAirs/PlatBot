#ifndef SCORE_BAR
#define SCORE_BAR

#include "GameManager.hpp"

class ScoreBar
{
public:

	//Rysuje pasek punktacji na pozycji pos, wyœwietlaj¹cy wartoœæ score. Parametr game to wskaŸnik na grê.
	void draw(GameManager * game, sf::Vector2f pos, int score);

	//Konstruktor klasy, tworz¹cy pasek punktów na pozycji o koordynatach x, y (lewy górny róg). Parametr game to wskaŸnik na grê.
	ScoreBar(float x, float y, GameManager * game);

	ScoreBar(){};

private:

	//Obiekt klasy sf::Vector2f. Pozycja paska punktacji (lewy górny róg).
	sf::Vector2f position;

	//Obiekt klasy sf::Font. Przechowuje czcionkê.
	sf::Font font;
};


#endif