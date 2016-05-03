#pragma once

#include <SFML\Graphics.hpp>

class Hitbox
{
public:
	
	//Sprawdza czy wystapi�a kolizja hitboxu z hitboxem thitbox
	bool checkCollision(Hitbox thitbox);

	//Sprawdza czy punkt zawiera si� wewn�trz hiboxa.
	bool checkCollision(sf::Vector2f point);

	//Sprawdza czy hitbox znajduje si� dok�adnie nad (i styka si�) z hitboxem thitbox.
	bool checkOnTop(Hitbox thitbox);

	//Przesuwa hitbox o koordynaty x, y.
	void move(float x, float y);

	//Zwraca sf::Vector2f z pozycj� lewego g�rnego rogu hitboxa.
	sf::Vector2f position();

	//Funkcja zwraca prostok�t hitboxa.
	sf::FloatRect checkBox();

	//Konstruktor klasy. Parametry x, y to po�o�enie lewego g�rnego rogu hitboxa, sizex i sizey to wymiary w pionie i poziomie hitboxa.
	Hitbox(int x, int y, int sizex, int sizey);
	
	//Destruktor
	Hitbox(){};

private:

	//Prostok�t b�d�cy hitboxem.
	sf::FloatRect hitbox;
	
};