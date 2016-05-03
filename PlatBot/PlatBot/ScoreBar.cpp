#include "ScoreBar.hpp"

//Rysuje pasek punktacji na pozycji pos, wy�wietlaj�cy warto�� score. Parametr game to wska�nik na gr�.
void ScoreBar::draw(GameManager * game, sf::Vector2f pos, int score)
{
	//Tekst wyniku do wy�wietlenia
	sf::Text text;

	//Pobieranie wyniku i przetwraczeni go na string
	std::string str = std::to_string(score);

	//Dodanie zer na pocz�tku liczby
	while (str.size() < 7)
	{
		str = "0" + str;
	}

	//Ustawienie pozycji paska
	position = pos;

	//Ustawienie tekstu
	text.setString(str);

	//Ustawienie czcionki
	text.setFont(font);

	//Ustawienie pozycji
	text.setPosition(sf::Vector2f(position.x + 1, position.y + 1));

	//Ustawienie rozmiaru czcionki
	text.setCharacterSize(8);

	//Ustawienie koloru czionki
	text.setColor(sf::Color::Black);

	//Pogrubienie czcionki
	text.setStyle(sf::Text::Bold);

	//Narysowanie obiektu na ekranie
	game->window.draw(text);
}

//Konstruktor klasy, tworz�cy pasek punkt�w na pozycji o koordynatach x, y (lewy g�rny r�g). Parametr game to wska�nik na gr�.
ScoreBar::ScoreBar(float x, float y, GameManager * game)
{
	if (!font.loadFromFile("fonts/font.ttf"))
	{
		throw std::runtime_error("Missing file: fonts/font.ttf");
	}

	const_cast<sf::Texture&>(font.getTexture(8)).setSmooth(false);

	position = sf::Vector2f(x, y);
}