#include "GameManager.hpp"
#include "Menu.hpp"
#include <Windows.h>

//G��wna funkcja programu
int main()
{
	try
	{
		//Tworzenie GameManagera
		GameManager game;
		//Tworzenie stanu Menu
		game.pushState(new Menu(&game, false));
		//Wej�cie do g��wnej p�tli gry
		game.loop();
	}
	catch (std::exception &ex)
	{
		MessageBoxA(NULL, ex.what(), "Error", MB_ICONERROR | MB_OK);
	}
	

	return 0;
}