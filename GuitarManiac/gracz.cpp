#include "stdafx.h"
#include "gracz.h"


gracz::gracz()
{
	punkty = 0;
	font.loadFromFile("WITCB.ttf");
}


gracz::~gracz()
{
}

void gracz::wyswietl_punkty(RenderWindow *window)
{
	string str = to_string(punkty);
	int str_size = str.size();
	liczba_punktow.setFont(font);
	liczba_punktow.setString(str);
	liczba_punktow.setPosition(100 - (str_size / 2) * 15, 495);
	liczba_punktow.setFillColor(Color::Black);
	window->draw(liczba_punktow);

}

void gracz::dodaj_punkty()
{
	punkty += 100;
}