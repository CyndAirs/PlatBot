#include "Projectile.hpp"

//Konstruktor klasy. Zmienna game przechowuje wskaŸnik na grê, type to typ ataku, faceLeft informuje w któr¹ stronê wzglêdem postaci wykonany jest atak (true je¿eli w lewo), friendly informuje czy atak zosta³ wykonany przez gracza (true) czy przeciwnika (false), x i y to koordynaty po³o¿enia lewego górnego rogu hitboxa ataku, speed to prêdkoœæ poruszania siê ataku.
Projectile::Projectile(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y, int speed) : Attack(game, type, faceLeft, friendly, x, y), speed(speed)
{

}

//Update'uje atak. map przechowuje planszê, dt przechowuje czas od ostatniego update'u.
void Projectile::update(std::vector<std::deque<BGElement*>> &map, const float dt)
{
	if (faceLeft == true) move(-speed * dt);
	else move(speed * dt);
	position = sf::Vector2f(hitbox.checkBox().left - A_HB_DIFF_W[type], hitbox.checkBox().top - A_HB_DIFF_W[type]);
}

//Przemieszcza obiekt o x pikseli w lewo.
void Projectile::move(float x)
{
	hitbox.move(x, 0);
}