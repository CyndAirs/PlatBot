#include "GameManager.hpp"
#include "Menu.hpp"
#include <Windows.h>

//G³ówna funkcja programu
int main()
{
	try
	{
		//Tworzenie GameManagera
		GameManager game;
		//Tworzenie stanu Menu
		game.pushState(new Menu(&game, false));
		//Wejœcie do g³ównej pêtli gry
		game.loop();
	}
	catch (std::exception &ex)
	{
		MessageBoxA(NULL, ex.what(), "Error", MB_ICONERROR | MB_OK);
	}
	

	return 0;
}