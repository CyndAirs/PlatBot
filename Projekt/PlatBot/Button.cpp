#include "Button.hpp"

//Konstruktor przycisku. Prametrami s¹: action - akcja przycisku, texname - nazwa tekstury oraz game - wskaŸnik na grê.
Button::Button(ButtonAction action, const std::string & texname, GameManager * game)
{
	
	//Ustawia akcjê przycisku
	this->action = action;
	//Ustawia pozycjê tekstury na spritesheecie
	texpos = sf::Vector2i(0, B_SIZE_Y * action);
	//Ustawia hitbox przycisku
	hitbox = Hitbox(B_POS_X[action], B_POS_Y[action], B_SIZE_X, B_SIZE_Y);
	//Ustawia teksturê
	texture = game->textures.getRef(texname);
}

//Rysuje przycisk. WskaŸnik game wskazuje na grê.
void Button::draw(GameManager * game)
{
	//Sprite przycisku
	sf::Sprite sprite;
	//Rozmiar przycisku
	sf::Vector2f size(hitbox.checkBox().width, hitbox.checkBox().height);
	//Kszta³t przycisku
	sf::RectangleShape shape(size);
	//Wybór tekstury na spritesheecie
	sprite.setTextureRect(sf::IntRect(texpos.x, texpos.y, hitbox.checkBox().width, hitbox.checkBox().height));
	//Ustawienie tekstury
	sprite.setTexture(texture);
	//Ustawienie pozycji na ekranie
	sprite.setPosition(sf::Vector2f(hitbox.checkBox().left, hitbox.checkBox().top));
	//Rysowanie przycisku
	game->window.draw(sprite);

}

//Zwraca true gdy punkt mpos znajduje siê wewn¹trz przycisku.
bool Button::CheckCollision(sf::Vector2f mpos)
{
	return hitbox.checkCollision(mpos);
}

//Zwraca akcjê przycisku.
const ButtonAction Button::ActionName()
{
	return action;
}



