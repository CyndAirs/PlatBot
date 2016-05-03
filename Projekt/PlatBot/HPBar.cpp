#include "HPBar.hpp"

//Poprawia po³o¿enie paska zycia na pos i rysuje pasek dla postaæ której zosta³o size punktów ¿ycia, wskaŸnik game wskazuje na grê.
void HPBar::draw(GameManager * game, sf::Vector2f pos, int size)
{
	//Sprite paska ¿ycia
	sf::Sprite sprite;

	//Rysowanie paska ¿ycia

	sprite.setTextureRect(sf::IntRect(1, 8, (HPBAR_W - 2) * size / P_HEALTH, HPBAR_H - 2));

	sprite.setTexture(texture);

	sprite.setPosition(sf::Vector2f(pos.x + 1, pos.y + 1));

	game->window.draw(sprite);

	//Rysowanie obramowania paska ¿ycia

	sprite.setTextureRect(sf::IntRect(0, 0, HPBAR_W, HPBAR_H));

	sprite.setTexture(texture);

	sprite.setPosition(sf::Vector2f(pos.x, pos.y));

	game->window.draw(sprite);
}

//Konstruktor klasy. Parametry x, y to po³o¿enie paska ¿ycia, wskaŸnik game wskazuje na grê.
HPBar::HPBar(float x, float y, GameManager * game)
{
	texture = game->textures.getRef("hpbar");
	position = sf::Vector2f(x, y);
}