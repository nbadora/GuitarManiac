#include "stdafx.h"
#include "gracz.h"


gracz::gracz()
{
	bonus = 1;
	punkty = 0;
	font.loadFromFile("WITCB.ttf");
	wasReset = false;
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

	str.clear();
	str.append("x");
	str.append( to_string(bonus));
	str_size = str.size();
	liczba_punktow.setString(str);
	liczba_punktow.setPosition(700 - (str_size / 2) * 15, 495);
	window->draw(liczba_punktow);
}

void gracz::dodaj_punkty()
{
	punkty += 100*bonus;
}

void gracz::zwieksz_bonus()
{
	bonus++;
	if (bonus > 3)
	{
		bonus = 3;
	}
}

void gracz::resetBonus()
{
	bonus = 1;
	wasReset = true;
}

bool gracz::returnReset()
{
	return wasReset;
}

void gracz::setResetFlag()
{
	wasReset = false;
}

int gracz::getBonus()
{
	return bonus;
}

void gracz::setName(string &s)
{
	nazwa = s;
	punkty = 0;
	bonus = 1;
	wasReset = false;
}

string gracz::getName()
{
	return nazwa;
}
string gracz::getSong()
{
	return piosenka;
}
int gracz::getPoints()
{
	return punkty;
}
void gracz::setSong(string &s)
{
	piosenka = s;
}