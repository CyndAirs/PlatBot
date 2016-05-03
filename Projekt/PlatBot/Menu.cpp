

#include "Menu.hpp"
#include "Level.hpp"
#include <string>

const std::string MENU_BUTTONS_TEX = "buttons";

//Rysuje menu.
void Menu::draw()
{
	//Ustawia menu
	this->game->window.setView(menuView);
	
	//Je¿eli menu nast¹pi³o po œmierci, jest czerwone i zamiast przycisku "start" jest przycisk "retry"
	if (!retry)
	{
		this->game->window.clear(sf::Color::Black);
	}
	else
	{
		this->game->window.clear(sf::Color::Red);
	}
	
	//Rysuje przyciski w menu
	for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); it++)
	{
		(*it)->draw(game);
	}
}

//Sprawdza akcje myszki.
void Menu::input()
{
	sf::Event event;

	//Obs³uga eventów
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
			{
				game->window.close();
				break;
			}
			/*case sf::Event::Resized:
			{
				menuView.setSize(event.size.width, event.size.height);
				game->bg.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
				game->bg.setScale(
					float(event.size.width) / float(game->bg.getTexture()->getSize().x),
					float(event.size.height) / float(game->bg.getTexture()->getSize().y));
				break;
			}*/
			case sf::Event::MouseButtonReleased:
			{
				//Przy puszczeniu przycisku myszki sprawdzanie hitboxów przycisków
				for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); it++)
				{
					if ((*it)->CheckCollision(game->window.mapPixelToCoords(sf::Mouse::getPosition(game->window))))
					{
						ButtonAction act = (*it)->ActionName();
						if (act == Start || act == Retry)
						{
							start();
						}
						else if (act == Exit)
						{
							game->window.close();
							break;
						}
					}
				}
			}
		}
	}

}




//Konstruktor menu, game jest wskaŸnikiem na grê, retry==true je¿eli menu ma ukazaæ siê w formie retry po przegranej grze.
Menu::Menu(GameManager* game, bool retry) : retry(retry)
{
	this->game = game;
	sf::Vector2f size = sf::Vector2f(VIEW_W, VIEW_H);
	menuView.setSize(size);
	size *= 0.5f;
	menuView.setCenter(size);

	//Tworzenie przycisków
	if (!retry)
	{
		buttons.push_back(new Button(Start, MENU_BUTTONS_TEX, game));
	}
	else
	{
		buttons.push_back(new Button(Retry, MENU_BUTTONS_TEX, game));
	}

	buttons.push_back(new Button(Exit, MENU_BUTTONS_TEX, game));
}

//Destruktor
Menu::~Menu()
{
	for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); it++)
	{
		delete (*it);
	}
}

//Rozpoczyna grê.
void Menu::start()
{
	game->pushState(new Level(this->game));
}