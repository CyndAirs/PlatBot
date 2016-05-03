#include "Level.hpp"

//Rysuje plansz�. 
void Level::draw()
{
	this->game->window.setView(levelView);
	this->game->window.clear(sf::Color::Blue);

	sf::Vector2f hpbarpos = levelView.getCenter() - levelView.getSize() * 0.5f + sf::Vector2f(HPBAR_X, HPBAR_Y); //!

	hpbar.draw(game, hpbarpos, playchar.checkHealth());

	sf::Vector2f scorebarpos = levelView.getCenter() - levelView.getSize() * 0.5f + sf::Vector2f(ScBAR_X, ScBAR_Y); //!

	scorebar.draw(game, scorebarpos, points);

	//Rysowanie mapy
	for (std::vector<std::deque<BGElement*>>::iterator it = map.begin(); it != map.end(); it++)
	{
		for (std::deque<BGElement*>::iterator it2 = it->begin(); it2 != it->end(); it2++)
		{
			(*it2)->draw(game);
		}
	}

	//Rysowanie atak�w
	for (std::vector<Attack*>::iterator it = attacks.begin(); it != attacks.end(); it++)
	{
		(*it)->draw(game);
	}
	
	//Rysowanie gracza
	playchar.draw(game);

	//Rysowanie przeciwnik�w
	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		(*it)->draw(game);
	}

}

//Funkcja poprawiaj�ca pozycj� ruchomego obiektu
void corrPos(MobileObject* ptr)
{
	ptr->corrPos();
}

//Update'uje plansze, dt to czas od ostatniego update'u.
void Level::update(const float dt)
{
	playchar.update(game, map, attacks, dt);

	sf::Vector2f center = levelView.getCenter();

	//Sprawdzanie pozycji gracza i przesuwanie sceny gdy grasz si� przemieszcza
	if (playchar.GetPosition().x > center.x)
	{
		center.x = playchar.GetPosition().x;

		if ((levelView.getSize().x + 32) < (2 * center.x))
		{
			generate();
			center.x -= 16;
			playchar.corrPos();

			for_each(enemies.begin(), enemies.end(), corrPos);

			for_each(attacks.begin(), attacks.end(), corrPos);
		}

		levelView.setCenter(center);
	}

	//Tworzenie iteratora dla przeciwnik�w
	std::vector<Enemy*>::iterator itenemy;

	//Update'owanie przeciwnik�w
	for (itenemy = enemies.begin(); itenemy != enemies.end(); itenemy++)
	{
		(*itenemy)->update(game, map, attacks, dt);
	}

	//Tworzenie iteratora dla atak�w
	std::vector<Attack*>::iterator itattack;

	//Update'owanie atak�w
	for (itattack = attacks.begin(); itattack != attacks.end(); itattack++)
	{
		(*itattack)->update(map, dt);
	}

	bool attackDelete = false;
	itattack = attacks.begin();
	std::string a;
	while (itattack != attacks.end())
	{
		//Sprawdzamy czy atak jest poza plansz�.
		if ((*itattack)->isOutside())
		{
			delete (*itattack);
			itattack = attacks.erase(itattack);
			continue;
		}
		//Sprawdzamy czy ataki fizyczne zako�czy�y si�
		if (typeid(**itattack) == typeid(Hit))
		{
			if ((dynamic_cast<Hit*>(*itattack)->expired()))
			{
				delete (*itattack);
				itattack = attacks.erase(itattack);
				continue;
			}
		}
		//Sprawdzamy czy atak uderza w garcza.	
		if (playchar.checkHit(*itattack))
		{
			attackDelete = true;
		}
		//Sprawdzamy czy atak uderza w jakich� przeciwnik�w
		itenemy = enemies.begin();
		while (itenemy != enemies.end() && (!attackDelete))
		{
			if ((*itenemy)->checkHit(*itattack))
			{
				attackDelete = true;
				//Ataki fizyczne mog� uderzy� w wi�cej przeciwnk�w, ale pociski nie
				if (typeid (**itattack) != typeid(Hit)) break; 
			}
			else itenemy++;
		}

		itenemy = enemies.begin();
		while (itenemy != enemies.end())
		{
			//Sprawdzanie czy przeciwnik znalaz� si� poza plansz�
			if ((*itenemy)->isOutside())
			{
				delete (*itenemy);
				itenemy = enemies.erase(itenemy);
			}
			//Sprawdzanie czy przeciwnik zgin��
			else if ((*itenemy)->checkHealth() <= 0)
			{
				delete (*itenemy);
				itenemy = enemies.erase(itenemy);
				points += 1;
			}
			//Je�eli przeciwnik ci�gle istnieje, inkrementujemy iterator
			else itenemy++;
		}

		//Sprawdzamy czy atak powinien zosta� usuni�ty
		if (attackDelete)
		{
			delete (*itattack);
			itattack = attacks.erase(itattack);
			attackDelete = false;
		}
		else itattack++;


	}

	//Sprawdzanie czy gracz zgin��
	if (playchar.checkHealth() == 0)
	{
		retry();
	}
}

//Prze��cza na stan Menu z warto�ci� retry=true w razie przegranej.
void Level::retry()
{
	game->pushState(new Menu(this->game, true));
}

//Sprawdza czy okno zosta�o zamkni�te.
void Level::input()
{
	sf::Event event;

	//Sprawdzanie eventu zamkni�cia
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		}
	}

}

//Konstruktor klasy. Parametr game wskazuje na gr�.
Level::Level(GameManager* game)
{
	this->game = game;
	sf::Vector2f size = sf::Vector2f(VIEW_W, VIEW_H);
	levelView.setSize(size);
	size *= 0.5f;
	levelView.setCenter(size);

	//Generujemy bazow� map�
	defmap =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 3, 0, 0, 0, 1, 2 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 2, 2, 2, 3, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};


	genMap();
	
	//Inicjalizacja postaci gracza
	playchar = Player(game, P_START_X, P_START_Y);

	//Inicjalizacja paska �ycia
	hpbar = HPBar(10, 10, game);

	//Inicjalizacja paska wyniku
	scorebar = ScoreBar(120, 10, game);
	
}

//Usuwa element planszy
void delete_BG(BGElement* ptr)
{
	delete ptr;
}

//Od�wie�a map generuj�c j� jeszcze raz na podstawie defmap.
void Level::genMap()
{
	for (std::vector<std::deque<BGElement*>>::iterator it = map.begin(); it != map.end(); it++)
	{
		for_each(it->begin(), it->end(), delete_BG);
		it->clear();
	}
	map.clear();
	for (int i = 0; i < 10; i++)
	{
		std::deque<BGElement*>temp;
		map.push_back(temp);
		for (int j = 0; j < 15; j++)
		{
			switch (defmap[i][j])
			{
			case 0:
			{
				map[i].push_back(new BGElement());
				break;
			}
			case 1:
			{
				map[i].push_back(new BGElement(game, StartBlock, j, i));
				break;
			}
			case 2:
			{
				map[i].push_back(new BGElement(game, MiddleBlock, j, i));
				break;
			}
			case 3:
			{
				map[i].push_back(new BGElement(game, EndBlock, j, i));
				break;
			}
			}
		}
	}
}

//Generuje przeciwnika typu type na polu planszy odpowiadaj�cym koordynatom x, y (w polach) na planie planszy.
void Level::spawn(int x, int y, int type)
{
	Enemy* enemy = new Enemy(game, (x - 1) * TILE_W + E_HB_DIFF_W[type], (y - 1) * TILE_H + E_HB_DIFF_H[type], type);

	enemies.push_back(enemy);
}

//Generuje now� kolumn� plany planszy algorytmem i umieszcza j� na ko�cu defmap. Usuwa pierwsz� kolumn� defmap.
void Level::generate()
{
	std::random_device generator;
	std::mt19937 mt(generator());
	std::uniform_real_distribution<double> dice(1, 10);
	int level = int(points/5);
	if (level >= 10) level = 9;
	if (level <= 1) level = 2;

	//Generowanie planu planszy do defmap, genruje linia po linii

	for (int i = 0; i < 10; i++)
	{
		//Usuwamy pierwsz� lini� mapy (poza ekranem)
		defmap[i].pop_front();

		switch (i)
		{
		case 2:
			
			defmap[i].push_back(Blank);
			
			//Je�eli blok poni�ej jest pocz�tkiem platformy losowanie spawny przeciwnika
			if ((defmap[i + 1][MAP_W - 2] == StartBlock) && ((dice(mt) - level) < 4))
			{
				if (dice(mt) > 5)
				{
					spawn(MAP_W - 1, i, 0);
				}
				else
				{
					spawn(MAP_W - 1, i, 1);
				}
			}

			break;

		case 3:
			
			//Sprawdzamy poprzedni blok
			switch (defmap[i][MAP_W - 2])
			{
			
			//Je�eli by� pusty losujemy czy zacz�� platform�
			case Blank:
				if ((dice(mt) / level) > 3)
				{
					defmap[i].push_back(StartBlock);
				}
				else if ((defmap[i][MAP_W - 4] == Blank) && (defmap[i+2][MAP_W - 4] == Blank))
				{
					defmap[i].push_back(StartBlock);
				}
				else
				{
					defmap[i].push_back(Blank);
				}
				break;
			
			//Je�eli platforma zacz�a si�, kontynuowanie jej
			case StartBlock:
				defmap[i].push_back(MiddleBlock);
				break;

			//Je�eli platforma ma ju� 2 bloki, losowanie czy si� zako�czy
			case MiddleBlock:
				if ((dice(mt) / count(defmap[i].begin(), defmap[i].end(), 2)) > 1)
				{
					defmap[i].push_back(MiddleBlock);
				}
				else
				{
					defmap[i].push_back(EndBlock);
				}
				break;

			//Je�eli platforma zako�czy�a si�, wstawianie pustego pola
			case EndBlock:
				defmap[i].push_back(Blank);
				break;

			default:
				defmap[i].push_back(Blank);

				break;
			}

			break;

		case 4:

			defmap[i].push_back(Blank);

			//Je�eli blok poni�ej jest pocz�tkiem platformy losowanie spawny przeciwnika
			if ((defmap[i + 1][MAP_W - 2] == StartBlock) && (dice(mt) - level) < 4)
			{
				if (dice(mt) > 5)
				{
					spawn(MAP_W - 1, i, 0);
				}
				else
				{
					spawn(MAP_W - 1, i, 1);
				}
			}

			break;

		case 5:

			switch (defmap[i][MAP_W - 2])
			{

			//Je�eli by� pusty losujemy czy zacz�� platform�
			case Blank:
				if ((dice(mt) / level) > 1)
				{
					defmap[i].push_back(StartBlock);
				}
				else if ((defmap[i - 2][MAP_W - 4] == Blank) && (defmap[i][MAP_W - 4] == Blank) && (defmap[i + 2][MAP_W - 4] == Blank))
				{
					defmap[i].push_back(StartBlock);
				}
				else
				{
					defmap[i].push_back(Blank);
				}
				break;

			//Je�eli platforma zacz�a si�, kontynuowanie jej
			case StartBlock:
				defmap[i].push_back(MiddleBlock);
				break;
			
			//Je�eli platforma ma ju� 2 bloki, losowanie czy si� zako�czy
			case MiddleBlock:
				if ((dice(mt) / count(defmap[i].begin(), defmap[i].end(), 2)) > 1)
				{
					defmap[i].push_back(MiddleBlock);
				}
				else
				{
					defmap[i].push_back(EndBlock);
				}
				break;

			//Je�eli platforma zako�czy�a si�, wstawianie pustego pola
			case EndBlock:
				defmap[i].push_back(Blank);
				break;

			default:
				defmap[i].push_back(Blank);

				break;
			}

			break;

		case 6:

			defmap[i].push_back(0);

			//Je�eli blok poni�ej jest pocz�tkiem platformy losowanie spawny przeciwnika
			if ((defmap[i + 1][MAP_W - 2] == StartBlock) && (dice(mt) - level) < 4)
			{
				if (dice(mt) > 5)
				{
					spawn(MAP_W - 1, i, 0);
				}
				else
				{
					spawn(MAP_W - 1, i, 1);
				}
			}

			break;

		case 7:

			switch (defmap[i][MAP_W - 2])
			{

			//Je�eli by� pusty losujemy czy zacz�� platform�
			case Blank:
				if ((dice(mt) / level) > 1)
				{
					defmap[i].push_back(StartBlock);
				}
				else if ((defmap[i - 2][MAP_W - 4] == Blank) && (defmap[i][MAP_W - 4] == Blank))
				{
					defmap[i].push_back(StartBlock);
				}
				else
				{
					defmap[i].push_back(Blank);
				}
				break;

			//Je�eli platforma zacz�a si�, kontynuowanie jej
			case StartBlock:
				defmap[i].push_back(MiddleBlock);
				break;

			//Je�eli platforma ma ju� 2 bloki, losowanie czy si� zako�czy
			case MiddleBlock:
				if ((dice(mt)/count(defmap[i].begin(), defmap[i].end(), 2)) > 1)
				{
					defmap[i].push_back(MiddleBlock);
				}
				else
				{
					defmap[i].push_back(EndBlock);
				}
				break;

			//Je�eli platforma zako�czy�a si�, wstawianie pustego pola
			case EndBlock:
				defmap[i].push_back(Blank);
				break;

			default:
				defmap[i].push_back(Blank);

				break;
			}

			break;

		default:

			defmap[i].push_back(Blank);

			break;
		}

	}
	genMap();
}

//Destruktor.
Level::~Level()
{
	for (std::vector<std::deque<BGElement*>>::iterator it = map.begin(); it != map.end(); it++)
	{
		for_each(it->begin(), it->end(), delete_BG);
	}

	for (std::vector<Attack*>::iterator it = attacks.begin(); it != attacks.end(); it++)
	{
		delete (*it);
	}

	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		delete (*it);
	}
}