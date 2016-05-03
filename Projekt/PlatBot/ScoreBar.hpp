#ifndef SCORE_BAR
#define SCORE_BAR

#include "GameManager.hpp"

class ScoreBar
{
public:

	//Rysuje pasek punktacji na pozycji pos, wy�wietlaj�cy warto�� score. Parametr game to wska�nik na gr�.
	void draw(GameManager * game, sf::Vector2f pos, int score);

	//Konstruktor klasy, tworz�cy pasek punkt�w na pozycji o koordynatach x, y (lewy g�rny r�g). Parametr game to wska�nik na gr�.
	ScoreBar(float x, float y, GameManager * game);

	ScoreBar(){};

private:

	//Obiekt klasy sf::Vector2f. Pozycja paska punktacji (lewy g�rny r�g).
	sf::Vector2f position;

	//Obiekt klasy sf::Font. Przechowuje czcionk�.
	sf::Font font;
};


#endif