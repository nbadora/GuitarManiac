#pragma once
#include "stdafx.h"

using namespace std;
using namespace sf;
#include "kreska.h"
#include "gracz.h"

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

};

