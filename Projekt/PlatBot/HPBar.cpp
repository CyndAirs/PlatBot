#include "HPBar.hpp"

//Poprawia po�o�enie paska zycia na pos i rysuje pasek dla posta� kt�rej zosta�o size punkt�w �ycia, wska�nik game wskazuje na gr�.
void HPBar::draw(GameManager * game, sf::Vector2f pos, int size)
{
	//Sprite paska �ycia
	sf::Sprite sprite;

	//Rysowanie paska �ycia

	sprite.setTextureRect(sf::IntRect(1, 8, (HPBAR_W - 2) * size / P_HEALTH, HPBAR_H - 2));

	sprite.setTexture(texture);

	sprite.setPosition(sf::Vector2f(pos.x + 1, pos.y + 1));

	game->window.draw(sprite);

	//Rysowanie obramowania paska �ycia

	sprite.setTextureRect(sf::IntRect(0, 0, HPBAR_W, HPBAR_H));

	sprite.setTexture(texture);

	sprite.setPosition(sf::Vector2f(pos.x, pos.y));

	game->window.draw(sprite);
}

//Konstruktor klasy. Parametry x, y to po�o�enie paska �ycia, wska�nik game wskazuje na gr�.
HPBar::HPBar(float x, float y, GameManager * game)
{
	texture = game->textures.getRef("hpbar");
	position = sf::Vector2f(x, y);
}