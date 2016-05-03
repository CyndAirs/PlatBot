#include "Hitbox.hpp"


//Sprawdza czy wystapi�a kolizja hitboxu z hitboxem thitbox
bool Hitbox::checkCollision(Hitbox thitbox)
{
	return hitbox.intersects(thitbox.checkBox());
}

//Sprawdza czy punkt zawiera si� wewn�trz hiboxa.
bool Hitbox::checkCollision(sf::Vector2f point)
{
	return hitbox.contains(point);
}

//Sprawdza czy hitbox znajduje si� dok�adnie nad (i styka si�) z hitboxem thitbox.
bool Hitbox::checkOnTop(Hitbox thitbox)
{
	if (int(thitbox.checkBox().top + thitbox.checkBox().height) == hitbox.top) return true;
	return false;
}

//Przesuwa hitbox o koordynaty x, y.
void Hitbox::move(float x, float y)
{
	hitbox.left += x;
	hitbox.top += y;
}

//Zwraca sf::Vector2f z pozycj� lewego g�rnego rogu hitboxa.
sf::Vector2f Hitbox::position()
{
	return sf::Vector2f(hitbox.left, hitbox.top);
}

//Funkcja zwraca prostok�t hitboxa.
sf::FloatRect Hitbox::checkBox()
{
	return hitbox;
}

//Konstruktor klasy. Parametry x, y to po�o�enie lewego g�rnego rogu hitboxa, sizex i sizey to wymiary w pionie i poziomie hitboxa.
Hitbox::Hitbox(int x, int y, int sizex, int sizey)
{
	hitbox = sf::FloatRect(x, y, sizex, sizey);
}