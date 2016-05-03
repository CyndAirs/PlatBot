#include "GameManager.hpp"
#include "State.hpp"

//Umieszcza na stosie obiekt klasy State wskazywany przez wska�nik state.
void GameManager::pushState(State* state)
{
	this->states.push_front(state);
	if (states.size() > 2)
	{
		popState();
	}
}

//Usuwa obiekt na szczycie stosu states je�eli stos nie jest pusty.
void GameManager::popState()
{
	delete this->states.back();
	this->states.pop_back();
}

//Zwraca wska�nik na obiekt na szczycie stosu states. Je�eli stos jest pusty zwraca nullptr.
State* GameManager::checkState()
{
	if (this->states.empty()) return nullptr;
	return this->states.front();
}

// Petla g��wna gry.
void GameManager::loop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		//Sprawdzanie zegara
		sf::Time elapsed = clock.restart();
		float time = elapsed.asSeconds();

		//Oczekiwanie na pojawienie si� stanu
		if (checkState() == nullptr) continue;
		//Sprawdzenie wej�cia dla stanu
		checkState()->input();
		//Update stanu
		checkState()->update(time);
		//Oczyszczenie okna
		this->window.clear(sf::Color::Black);
		//Rysowanie stanu
		checkState()->draw();
		//Wy�wietlanie okna
		this->window.display();
	}
}

//Konstrutor klasy, tworzy okno gry.
GameManager::GameManager()
{
	this->window.create(sf::VideoMode(VIEW_W, VIEW_H), "PlatBot", sf::Style::Default);
	this->window.setFramerateLimit(60);
}

//Destruktor
GameManager::~GameManager()
{
	while (!this->states.empty()) popState();
}