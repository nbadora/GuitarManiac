#pragma once
#include "stdafx.h"

using namespace std;
using namespace sf;


class gracz
{
private:
	int punkty;
	int bonus;
	Text liczba_punktow;
	Font font;
	bool wasReset;
public:
	gracz();
	~gracz();

	void wyswietl_punkty(RenderWindow *window);
	void dodaj_punkty();
	void zwieksz_bonus();
	void resetBonus();
	bool returnReset();
	void setResetFlag();
	int getBonus();
};

