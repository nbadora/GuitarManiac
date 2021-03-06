#include "stdafx.h"
#include "kreska.h"


kreska::kreska(int size, float x, float y, string sciezka) //rozmiar minimum 2
{
	texture.loadFromFile(sciezka);
	texture.setSmooth(true);
	dlugosc = size;
	for (int i = 0; i < size; i++)
	{
		sprite_kreski.push_back(new Sprite(texture));
	}
	if (size == 2)
	{
		sprite_kreski[0]->setTextureRect(IntRect(0, 144, 72, 72));
		sprite_kreski[0]->setOrigin(36, 36);
		sprite_kreski[0]->setPosition(x, y);
		sprite_kreski[1]->setTextureRect(IntRect(0, 0, 72, 72));
		sprite_kreski[1]->setOrigin(36, 36);
		sprite_kreski[1]->setPosition(x, y);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (i == 0)
			{
				sprite_kreski[i]->setTextureRect(IntRect(0, 144, 72, 72));
			}
			else if (i == (size - 1))
			{
				sprite_kreski[i]->setTextureRect(IntRect(0, 0, 72, 72));
			}
			else
			{
				sprite_kreski[i]->setTextureRect(IntRect(0, 72, 72, 72));
			}
			sprite_kreski[i]->setOrigin(36, 36);
			sprite_kreski[i]->setPosition(x, y - i * 36);
		}
	}
	trzyma_przycisk = false;
	przyznaje_punkty = true;
	zloty = false;
	actP = 0;
	maxP = (size-2) *100;		//trzeba poprawic max pkt, chyba *72
}


Vector2f kreska::poczatekKreski()
{
	Vector2f poczatek = sprite_kreski[0]->getPosition();
	poczatek.y += 36;
	return poczatek;
}

Vector2f kreska::koniecKreski()
{
	Vector2f koniec = sprite_kreski[sprite_kreski.size()-1]->getPosition();
	koniec.y -= 36;
	return koniec;
}



kreska::~kreska()
{
}

void kreska::rysuj_kreske(RenderWindow *window)
{
	for (auto i : sprite_kreski)
	{
		window->draw(*i);
	}
}

void kreska::move()
{
	for (int i = 0; i < dlugosc; i++)
	{
		sprite_kreski[i]->move(0, 1);	//predkosc
	}
}

void kreska::correct(float y)
{
	for (int i = 0; i < dlugosc; i++)
	{
		sprite_kreski[i]->move(0, y);
	}
}

bool kreska::poza_oknem()
{
	if (sprite_kreski[sprite_kreski.size()-1]->getPosition().y > 640)
	{
		return true;
	}
	return false;
}

bool kreska::przyznaj_punkty(gracz &player)
{
	bool wyswietl_efekt = false;
	if (trzyma_przycisk && przyznaje_punkty)	//sprawdza czy gracz trzyma przycisk i moze dostawac punkty
	{
		wyswietl_efekt = true;
		if (odstep_miedzy_punktami.getElapsedTime().asMilliseconds() > 50)	//czas od ostatniego dodania punktow
		{
			player.dodaj_punkty();	//dodjae punkty
			actP += 100;	//aktualnie zdobte pnkty z kreski
			odstep_miedzy_punktami.restart();	//restart zegara
			if (maxP <= actP)	//sprawdz czy zdobylismy prawie maksa za kreske
			{
				zloty = true;	//kolor kreski na zloty
			}
		}
	}
	else
	{
		//kara za niepotrzebne naciskanie
	}
	return wyswietl_efekt;
}

void kreska::odblokuj_punkty()
{
	trzyma_przycisk = true;
}

bool kreska::sprawdz_bonus()
{
	return zloty;
}

//do poprawienia
void kreska::blokuj_punkty(gracz &player)
{
	if (maxP <= actP)
	{
		zloty = true;
		cout << "udalo sie\n";
	}
	else
	{
		texture.loadFromFile("grafiki/greycos.png");
		for (int i = 0; i < sprite_kreski.size(); i++)
		{
			if (i == 0)
			{
				sprite_kreski[0]->setTexture(texture);
				sprite_kreski[0]->setTextureRect(IntRect(0, 144, 72, 72));
			}
			else if (i < sprite_kreski.size() - 1)
			{
				sprite_kreski[i]->setTexture(texture);
				sprite_kreski[i]->setTextureRect(IntRect(0, 72, 72, 72));
			}
			else if (i == sprite_kreski.size() - 1)
			{
				sprite_kreski[sprite_kreski.size() - 1]->setTexture(texture);
				sprite_kreski[sprite_kreski.size() - 1]->setTextureRect(IntRect(0, 0, 72, 72));
			}
		}
		cout << "nie udalo sie\n";
		player.resetBonus();
	}
	przyznaje_punkty = false;

	if (zloty)
	{
		if (!bonusGiven)
		{
			bonusGiven = true;
			player.zwieksz_bonus();
		}
		texture.loadFromFile("grafiki/goldcos.png");
		for (int i = 0; i < sprite_kreski.size(); i++)
		{
			if (i == 0)
			{
				sprite_kreski[0]->setTexture(texture);
				sprite_kreski[0]->setTextureRect(IntRect(0, 144, 72, 72));
			}
			else if (i < sprite_kreski.size() - 1)
			{
				sprite_kreski[i]->setTexture(texture);
				sprite_kreski[i]->setTextureRect(IntRect(0, 72, 72, 72));
			}
			else if (i == sprite_kreski.size()-1)
			{
				sprite_kreski[sprite_kreski.size() - 1]->setTexture(texture);
				sprite_kreski[sprite_kreski.size() - 1]->setTextureRect(IntRect(0, 0, 72, 72));
			}
		}
	}
}

Vector2f kreska::polozenie()
{
	return Vector2f(0, 0);
}