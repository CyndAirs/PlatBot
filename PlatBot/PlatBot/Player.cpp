#include "Player.hpp"

//Update'uje postaæ, sprawdza input z klawiatury. Parametrami s¹ game, czyli wskaŸnik na grê; map, czyli plansza; attacks, czyli vector ataków, do którego maj¹ byæ dopisane ataki wykonane przez postaæ; dt, czyli czas od ostatniego update'u.
void Player::update(GameManager * game, std::vector<std::deque<BGElement*>> &map, std::vector<Attack*> &attacks, const float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		move(map, -P_SPEED, 0);
		faceLeft = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		move(map, P_SPEED, 0);
		faceLeft = false;
	}

	//X - atak zasiegowy
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		if (cooldown <= 0)
		{
			//Sprawdzanie kierunku ataku
			if (faceLeft)
			{
				attacks.push_back(new Projectile(game, P_A_TYPE[0], faceLeft, true, position.x + spriteSize.x - P_A_POS_X[P_A_TYPE[0]] - A_HB_SIZE_W[0], position.y + P_A_POS_Y[P_A_TYPE[0]], P_PROJECTILE_SPEED));
			}
			else
			{
				attacks.push_back(new Projectile(game, P_A_TYPE[0], faceLeft, true, position.x + P_A_POS_X[P_A_TYPE[0]], position.y + P_A_POS_Y[P_A_TYPE[0]], P_PROJECTILE_SPEED));
			}
			cooldown = P_ATT_CD;
		}
		animation.setTemp(RangedAttack, A_TIMER[P_A_TYPE[0]]);

	}

	//Z - atak fizyczny
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		if (cooldown <= 0)
		{
			//Sprawdzanie kierunku ataku
			if (faceLeft)
			{
				attacks.push_back(new Hit(game, P_A_TYPE[1], faceLeft, true, position.x + spriteSize.x - P_A_POS_X[P_A_TYPE[1]] - A_HB_SIZE_W[1], position.y + P_A_POS_Y[P_A_TYPE[1]]));
			}
			else
			{
				attacks.push_back(new Hit(game, P_A_TYPE[1], faceLeft, true, position.x + P_A_POS_X[P_A_TYPE[1]], position.y + P_A_POS_Y[P_A_TYPE[1]]));
			}
			cooldown = P_ATT_CD;
		}
		animation.setTemp(MeleeAttack, A_TIMER[P_A_TYPE[1]]);
	}

	if (cooldown > 0) cooldown -= dt;

	//Sprawdzenie czy postaæ jest na ziemi
	if (grounded)
	{
		//Skok
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			acc = -BASE_ACC;
			grounded = false;
			animation.setDefault(Jump);
		}
		animation.setDefault(Stand);
	}
	else
	{
		//Upadek

		acc += GRAVITY * dt;

		move(map, 0, acc * dt);

		animation.setDefault(Jump);
	}

	//Smieræ w wyniku spadku z planszy
	if (hitbox.checkBox().top > MAP_H*TILE_H)
	{
		health = 0;
	}

	frame = animation.checkFrame(dt);
}

//Ustawia pozycjê sprite'a.
void Player::fixPos()
{
	position = sf::Vector2f(hitbox.checkBox().left - P_HB_DIFF_W, hitbox.checkBox().top - P_HB_DIFF_H);
}

//Przemieszcza hitbox postaci po planszy. Parametr map to plansza, a x i y to wartoœci o jakie przesuwa siê postaæ.
void Player::move(std::vector<std::deque<BGElement*>> &map, float x, float y)
{
	if (x != 0)
	{
		hitbox.move(x, 0);

		if (hitbox.checkBox().left < 0)
		{
			hitbox.move(-x, 0);
			return;
		}

		//Sprawdzenie czy postaæ nie zesz³a z platformy na której sta³a
		if (grounded == true)
		{
			for (int i = int(hitbox.checkBox().left / TILE_W); i <= int((hitbox.checkBox().left + hitbox.checkBox().width) / TILE_W); i++)
			{
				for (int j = int(hitbox.checkBox().top / TILE_H); j <= int((hitbox.checkBox().top + hitbox.checkBox().height) / TILE_H); j++)
				{

					if (map[j][i]->checkHB().checkOnTop(hitbox))
					{
						fixPos();
						return;
					}
				}
			}
			grounded = false;
		}
		fixPos();
		return;
	}

	if (y != 0)
	{
		hitbox.move(0, y);

		for (int i = int(hitbox.checkBox().left / TILE_W); i <= int((hitbox.checkBox().left + hitbox.checkBox().width) / TILE_W); i++)
		{
			for (int j = int(hitbox.checkBox().top / TILE_H); j <= int((hitbox.checkBox().top + hitbox.checkBox().height) / TILE_H); j++)
			{
				if ((j > 0) && (j < MAP_H) && (i > 0) && (i < MAP_W) && map[j][i]->checkHB().checkCollision(hitbox))
				{
					//Postaæ napotka³a locie blok, nale¿y sprawiæ by na nim stanê³a je¿eli spada³a z góry.
					BgId id = map[j][i]->checkID();
					if (id == StartBlock || id == MiddleBlock || id == EndBlock)
					{
						if (y > 0)
						{
							hitbox.move(0, -y);

							while (!map[j][i]->checkHB().checkOnTop(hitbox))
							{
								if (map[j][i]->checkHB().checkBox().top > (hitbox.checkBox().top + hitbox.checkBox().height))
								{
									hitbox.move(0, 1);
								}
								else break;
							}

							if (map[j][i]->checkHB().checkOnTop(hitbox))
							{
								grounded = true;
							}
							else
							{
								hitbox.move(0, y);
							}
							continue;
						}
						else continue;
					}
				}
			}
		}
	}
	fixPos();
	return;
}

//Sprawdza kolizjê obiektu z atakiem, je¿eli wyst¹pi³a, zadaje mu obra¿enia i zwraca true.
bool Player::checkHit(Attack * attack)
{
	if (this->hitbox.checkCollision(attack->getHB()) && (!attack->checkFriendly()))
	{
		damage(1);
		return true;
	}
	else return false;
}

//Zwraca pozycjê sprite'a postaci (lewy górny róg).
sf::Vector2f Player::GetPosition()
{
	return position;
}

//Konstruktor klasy. Parametr game to wskaŸnik na grê, a parametry x i y to pozycja sprite'a postaci (lewy górny róg).
Player::Player(GameManager * game, float x, float y)
{

	position = sf::Vector2f(x, y);

	hitbox = Hitbox(x + P_HB_DIFF_W, y + P_HB_DIFF_H, P_HB_SIZE_W, P_HB_SIZE_H);

	grounded = true;

	texture = game->textures.getRef("player");

	acc = BASE_ACC;

	health = P_HEALTH;

	faceLeft = false;

	spriteSize = sf::Vector2i(P_SPRITE_W, P_SPRITE_H);

	type = 0;

	frame = 0;
}
