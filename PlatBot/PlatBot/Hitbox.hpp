#pragma once

#include <SFML\Graphics.hpp>

class Hitbox
{
public:
	
	//Sprawdza czy wystapi³a kolizja hitboxu z hitboxem thitbox
	bool checkCollision(Hitbox thitbox);

	//Sprawdza czy punkt zawiera siê wewn¹trz hiboxa.
	bool checkCollision(sf::Vector2f point);

	//Sprawdza czy hitbox znajduje siê dok³adnie nad (i styka siê) z hitboxem thitbox.
	bool checkOnTop(Hitbox thitbox);

	//Przesuwa hitbox o koordynaty x, y.
	void move(float x, float y);

	//Zwraca sf::Vector2f z pozycj¹ lewego górnego rogu hitboxa.
	sf::Vector2f position();

	//Funkcja zwraca prostok¹t hitboxa.
	sf::FloatRect checkBox();

	//Konstruktor klasy. Parametry x, y to po³o¿enie lewego górnego rogu hitboxa, sizex i sizey to wymiary w pionie i poziomie hitboxa.
	Hitbox(int x, int y, int sizex, int sizey);
	
	//Destruktor
	Hitbox(){};

private:

	//Prostok¹t bêd¹cy hitboxem.
	sf::FloatRect hitbox;
	
};