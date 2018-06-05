#pragma once
#include "stdafx.h"

using namespace std;
using namespace sf;

class kreska:public obiekt
{
private:
	int dlugosc;
	vector <Sprite*> sprite_kreski;
public:
	kreska(int size, float x, float y, string sciezka);
	~kreska();

	void rysuj_kreske(RenderWindow *window);
	void move();
	bool poza_oknem();
};

