#include "Attack.hpp"


//Sprawdza czy Atatck znajduje si� poza plansz�.Je�eli tak, zwraca true.
bool Attack::isOutside()
{
	//Pobranie pozycji hitboxa
	int x = (hitbox.checkBox().left + hitbox.checkBox().width / 2) / TILE_W;
	//Por�wnanie wyniku z brzegami planszy
	if ((x < 0) || (x >(MAP_W))) return true;
	return false;
}

//Sprawdza czy atak zosta� wykonany przez gracza (zwraca true) czy przeciwnika.(zwraca false)
bool Attack::checkFriendly()
{
	return isFriendly;
}

//Konstruktor klasy. Zmienna game przechowuje wska�nik na gr�, type to typ ataku, faceLeft informuje w kt�r� stron� wzgl�dem postaci wykonany jest atak(true je�eli w lewo), friendly informuje czy atak zosta� wykonany przez gracza(true) czy przeciwnika(false), x i y to koordynaty po�o�enia lewego g�rnego rogu hitboxa ataku.
Attack::Attack(GameManager * game, int type, bool faceLeft, bool friendly, int x, int y) : isFriendly(friendly)
{
	frame = 0;
	this->type = type;
	//Pobieranie tekstury
	texture = game->textures.getRef("attacks");
	//Ustawianie hitboxa
	hitbox = Hitbox(x, y, A_HB_SIZE_W[type], A_HB_SIZE_H[type]);
	//Ustawianie pozycji ataku
	position = sf::Vector2f(x - A_HB_DIFF_W[type], y - A_HB_DIFF_H[type]);
	//Ustawianie w kt�r� stron� atak b�dzie si� porusza�
	this->faceLeft = faceLeft;
	//Ustawianie wielko�ci sprite'a
	spriteSize = sf::Vector2i(A_SPRITE_W, A_SPRITE_H);
}



