#pragma once
#include "stdafx.h"
#include "gracz.h"

using namespace std;
using namespace sf;

class kreska:public obiekt
{
private:
	int dlugosc;					//dlugosc wektora/kreski
	vector <Sprite*> sprite_kreski;	//wektor sprite'ow
	bool trzyma_przycisk;			//czy trzymamy odpowiedni button
	bool przyznaje_punkty;			//przyznajemy punkty tak dlugo az nie puscimy buttona lub nie jest juz poza kreska
	bool zloty;						//zmienia kolor kreski na zloty gdy sie dostalo za nia max pkt
	int maxP;
	int actP;
	Clock odstep_miedzy_punktami;
public:
	kreska(int size, float x, float y, string sciezka);
	~kreska();

	void rysuj_kreske(RenderWindow *window);
	void move();
	bool poza_oknem();
	void przyznaj_punkty(gracz &player);
	Vector2f polozenie();
	Vector2f poczatekKreski();
	Vector2f koniecKreski();
	void blokuj_punkty();
	void odblokuj_punkty();


};

