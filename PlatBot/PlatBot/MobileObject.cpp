#include "MobileObject.hpp"

//Przemieszcza obiekt o d³ugoœæ jednego pola planszy.
void MobileObject::corrPos()
{
	position.x -= TILE_W;
	hitbox.move(-TILE_W, 0);
}

//Zwraca Hitobox obiektu.
Hitbox MobileObject::getHB()
{
	return hitbox;
}

//Rysuje obiekt. WskaŸnik game wskazuje na grê.
void MobileObject::draw(GameManager * game)
{
	//Sprite obiektu
	sf::Sprite sprite;

	//Pozycja sprite'a obiektu na ekranie
	sf::Vector2f newpos = sf::Vector2f(position.x + spriteSize.x*0.5f, position.y + spriteSize.y*0.5f);

	//Ustawianie pozycji sprite'a obiektu na spritesheecie
	sprite.setTextureRect(sf::IntRect(spriteSize.x*frame, spriteSize.y * type, spriteSize.x, spriteSize.y));

	//Ustawianie tekstury
	sprite.setTexture(texture);

	//Ustawianie punktu obrotu spritera
	sprite.setOrigin(0.5f*spriteSize.x, 0.5f*spriteSize.y);

	//Ustawianie czy sprite jest obrócony
	if (!faceLeft)
	{
		sprite.scale(-1.f, 1.f);
	}

	//Ustawianie pozycji spirite'a
	sprite.setPosition(newpos);

	//Rysowanie obiektu
	game->window.draw(sprite);
}


