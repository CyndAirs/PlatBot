#include "Button.hpp"

//Konstruktor przycisku. Prametrami s�: action - akcja przycisku, texname - nazwa tekstury oraz game - wska�nik na gr�.
Button::Button(ButtonAction action, const std::string & texname, GameManager * game)
{
	
	//Ustawia akcj� przycisku
	this->action = action;
	//Ustawia pozycj� tekstury na spritesheecie
	texpos = sf::Vector2i(0, B_SIZE_Y * action);
	//Ustawia hitbox przycisku
	hitbox = Hitbox(B_POS_X[action], B_POS_Y[action], B_SIZE_X, B_SIZE_Y);
	//Ustawia tekstur�
	texture = game->textures.getRef(texname);
}

//Rysuje przycisk. Wska�nik game wskazuje na gr�.
void Button::draw(GameManager * game)
{
	//Sprite przycisku
	sf::Sprite sprite;
	//Rozmiar przycisku
	sf::Vector2f size(hitbox.checkBox().width, hitbox.checkBox().height);
	//Kszta�t przycisku
	sf::RectangleShape shape(size);
	//Wyb�r tekstury na spritesheecie
	sprite.setTextureRect(sf::IntRect(texpos.x, texpos.y, hitbox.checkBox().width, hitbox.checkBox().height));
	//Ustawienie tekstury
	sprite.setTexture(texture);
	//Ustawienie pozycji na ekranie
	sprite.setPosition(sf::Vector2f(hitbox.checkBox().left, hitbox.checkBox().top));
	//Rysowanie przycisku
	game->window.draw(sprite);

}

//Zwraca true gdy punkt mpos znajduje si� wewn�trz przycisku.
bool Button::CheckCollision(sf::Vector2f mpos)
{
	return hitbox.checkCollision(mpos);
}

//Zwraca akcj� przycisku.
const ButtonAction Button::ActionName()
{
	return action;
}



