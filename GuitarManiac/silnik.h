#pragma once
#include "stdafx.h"

using namespace std;
using namespace sf;
#include "kreska.h"
#include "gracz.h"
#include <vector>
#include "pulsacyjny.h"
#include "enum_gameState.h"
#include <fstream>

class silnik
{
private:
	RenderWindow window;
	vector <przycisk*> buttons;
	vector <efekt_wizualny*> efekty_wizualne;
	vector <kreska*> kreski;
	gracz player_one;
	Music music;
	bool start_music;
	bool inGame;
	Sprite background;
	Texture bg_texture;
	Clock muteTime;

	vector <pulsacyjny> efekty_pulasacyjne;
public:
	
	
	silnik();
	~silnik();

	void start();
	void rysuj_wszystko();

	void add_lines();
	void check_A_button();
	void check_S_button();
	void check_D_button();
	void check_F_button();

	void kreski_poza_polem();


	//----------------
	void menu_gry(gameState &state);
	void loadTop(gameState &state);

};

