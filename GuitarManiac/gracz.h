#pragma once
#include "stdafx.h"

using namespace std;
using namespace sf;


class gracz
{
private:
	int punkty;
	Text liczba_punktow;
	Font font;
public:
	gracz();
	~gracz();

	void wyswietl_punkty(RenderWindow *window);
	void dodaj_punkty();
};

