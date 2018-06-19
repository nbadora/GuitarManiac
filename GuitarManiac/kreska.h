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
	bool bonusGiven = false;
public:
	kreska(int size, float x, float y, string sciezka);
	~kreska();

	void rysuj_kreske(RenderWindow *window);	//rysuje kreske na oknie
	void move();	//przesuwa kreske
	bool poza_oknem();	//sprawdza czy kreska jest poza oknem - usuwa j¹
	bool przyznaj_punkty(gracz &player);	//dodaje punkty graczowi, zwraca boola czy pokazac efekt czy nie
	Vector2f polozenie();
	Vector2f poczatekKreski();//zwraca poczatek kreski
	Vector2f koniecKreski();//zwraca koniec kreski
	void blokuj_punkty(gracz &player);	//niepozwala przyznawac wiecej punktow
	void odblokuj_punkty();	//odblokowuje przyznawanie punktow
	bool sprawdz_bonus();	//zwraca czy gold =true or false

};

