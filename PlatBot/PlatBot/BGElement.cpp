#include "BGElement.hpp"

//Zwraca Hitbox pola planszy.
Hitbox BGElement::checkHB()
{
	return hitbox;
}

//Rysuje pole planszy. WskaŸnik game wskazuje na grê.
void BGElement::draw(GameManager* game)
{
	if (id != 0) // Nie rysuje pustego pola
	{
		sf::Sprite sprite;

		sprite.setTextureRect(sf::IntRect((id - 1) * TILE_W, 0, TILE_W, TILE_H));

		sprite.setTexture(texture);

		sprite.setPosition(pos.x, pos.y);

		game->window.draw(sprite);
	}
}

//Zwraca rodzaj pola planszy.
BgId BGElement::checkID()
{
	return id;
}

//Domyslny konstruktor. Nadaje polu planszy Id = 0;
BGElement::BGElement() :
id(Blank)
{}

//Konstruktor pola planszy. WskaŸnik game wskazuje na grê. id zawiera rodzaj pola, cox, coy to koordynaty na mapie planszy (w polach).
BGElement::BGElement(GameManager* game, BgId id, int cox, int coy) : id(id)
{
	//Ustawianie pozycji
	pos = sf::Vector2i(TILE_W * cox, TILE_H * coy);
	//Ustawianie tekstury
	texture = game->textures.getRef("tiles");
	//Ustawianie hitboxu
	hitbox = Hitbox(pos.x + BG_HB_DIFF_W[id], pos.y + BG_HB_DIFF_H[id], BG_HB_SIZE_W[id], BG_HB_SIZE_H[id]);
}

