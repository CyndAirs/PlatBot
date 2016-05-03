#include "Enemy.hpp"


//Update'uje obiekt. WskaŸnik game wskazuje na grê, map zawiera planszê, attack zawiera wektor wskaŸników na ataki, do którego ewentualne nowe ataki maj¹ byæ przypisane, dt wskazuje ró¿nicê czasu.
void Enemy::update(GameManager * game, std::vector<std::deque<BGElement*>> &map, std::vector<Attack*> &attacks, const float dt)
{
	//Zapisanie pozycji w x
	int x = int((hitbox.checkBox().left + hitbox.checkBox().width / 2) / TILE_W);
	//Zapisanie pozycji w y
	int y = int((hitbox.checkBox().top + hitbox.checkBox().height) / TILE_H);
	//Sprawdzenie czy przeciwnik nie jest poza map¹
	if ((x < 0) || (x >= MAP_W)) return;
	//Sprawdzenie czy przeciwnik stoi na platformie
	while ((map[y][x]->checkID() != StartBlock) && (map[y][x]->checkID() != MiddleBlock) && (map[y][x]->checkID() != EndBlock) && (y < 10))
	{
		y++;
		if (y >= MAP_H) return;
	}

	//Przeciwnik zawraca gdy wejdzie na skrajny blok platformy przynajmniej po³ow¹ hiboxa.
	switch (map[y][x]->checkID())
	{
	case 1:
	{
		move(E_SPEED[type] * dt);
		faceLeft = false;
		break;
	}
	case 3:
	{
		move(-E_SPEED[type] * dt);
		faceLeft = true;
		break;
	}
	default:
	{
		if (faceLeft == true) move(-E_SPEED[type] * dt);
		if (faceLeft == false) move(E_SPEED[type] * dt);
		break;
	}
	}

	//Sprawdzenie czy przeciwnik bêdzie atakowa³
	if (cooldown < 0)
	{
		cooldown = E_ATT_CD[type];
		//Sprawdzenie w któr¹ stronê bêdzie wykonany atak
		if (faceLeft)
		{
			if (E_MELEE[type])
			{
				attacks.push_back(new Hit(game, E_A_TYPE[type], faceLeft, false, position.x + E_SPRITE_W - E_A_POS_X[type] - A_HB_SIZE_W[E_A_TYPE[type]], position.y + E_A_POS_Y[type]));
			}
			if (E_RANGED[type])
			{
				attacks.push_back(new Projectile(game, E_A_TYPE[type], faceLeft, false, position.x + E_SPRITE_W - E_A_POS_X[type] - A_HB_SIZE_W[E_A_TYPE[type]], position.y + E_A_POS_Y[type], E_PROJECTILE_SPEED[type]));
			}
		}
		else
		{
			if (E_MELEE[type])
			{
				attacks.push_back(new Hit(game, E_A_TYPE[type], faceLeft, false, position.x + E_A_POS_X[type], position.y + E_A_POS_Y[type]));
			}
			if (E_RANGED[type])
			{
				attacks.push_back(new Projectile(game, E_A_TYPE[type], faceLeft, false, position.x + E_A_POS_X[type], position.y + E_A_POS_Y[type], E_PROJECTILE_SPEED[type]));
			}
		}
	}
	else
	{
		cooldown -= dt;
	}


}

//Sprawdza kolizjê obiektu z atakiem, je¿eli wyst¹pi³a, zadaje mu obra¿enia i zwraca true.
bool Enemy::checkHit(Attack * attack)
{
	if (this->hitbox.checkCollision(attack->getHB()) && attack->checkFriendly())
	{
		//Przeciwnicy mog¹ otrzymywaæ ró¿ne obra¿enia od ró¿nych klas ataków.
		if (typeid(*attack) == typeid(Hit))
		{
			return damage(E_HIT_DMG_TKN[type]);
		}
		if (typeid(*attack) == typeid(Projectile))
		{
			return damage(E_PROJECTILE_DMG_TKN[type]);
		}
	}
	else return false;
}

//Zwraca true je¿eli obiekt jest poza plansz¹.
bool Enemy::isOutside()
{
	if (((hitbox.checkBox().left + hitbox.checkBox().width / 2) / 16) < 0) return true;
	return false;
}

//Przemieszcza obiekt o x pikseli w prawo.
void Enemy::move(float x)
{
	position.x += x;
	hitbox.move(x, 0);
}

//Enemy(GameManager * game, float x, float y, int type)
Enemy::Enemy(GameManager * game, float x, float y, int type)
{
	position = sf::Vector2f(x, y);

	faceLeft = true;

	texture = game->textures.getRef("enemies");

	hitbox = Hitbox(x + E_HB_DIFF_W[type], y + E_HB_DIFF_H[type], E_HB_SIZE_W[type], E_HB_SIZE_H[type]);

	cooldown = 0.5f*E_ATT_CD[type];

	health = E_HEALTH[type];

	spriteSize = sf::Vector2i(E_SPRITE_W, E_SPRITE_H);

	this->type = type;

	frame = 0;
}
