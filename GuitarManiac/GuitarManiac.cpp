#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include "ball.h"
#include "enum_gameState.h"
using namespace sf;
using namespace std;


int main()
{

	silnik engine;
	gameState state = MENU;
	bool quit = false;
	while (!quit)
	{
		switch (state)
		{
		case MENU:
			engine.menu_gry(state);
			break;
		case WYBOR_PIOSENKI:
			engine.nowa_gra(state);
			engine.nowy_gracz();
			engine.poziom_trudnosci();
			engine.start();
			break;

		case NAJLEPSI_GRACZE:
			engine.loadTop(state);
			break;

		case WYJSCIE:
			quit = true;
			break;

		default:
			break;
		}
		//engine.start();
	}


	//clear memory
	return 0;
}