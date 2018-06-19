#include "stdafx.h"
#include "pulsacyjny.h"


pulsacyjny::pulsacyjny(float x, float y)
{
	rs.loadFromFile("grafiki/rseries.png");
	bs.loadFromFile("grafiki/bseries.png");
	gs.loadFromFile("grafiki/gseries.png");
	sprite.setTexture(rs);
	sprite.setTextureRect(IntRect(0, 0, 97, 97));
	sprite.setOrigin(48.5, 48.5);
	sprite.setPosition(x, y);
}


pulsacyjny::~pulsacyjny()
{
}

void pulsacyjny::next_frame()
{
	if (frame_Time.getElapsedTime().asMilliseconds() > 50)
	{
		sprite.setTextureRect(IntRect(sprite.getTextureRect().left + 97,0, 97, 97));
		frame_Time.restart();
	}
	if (sprite.getTextureRect().left >= 485)
	{
		sprite.setTextureRect(IntRect(0, 0, 97, 97));
	}
}


void pulsacyjny::odblokuj()
{
	rysowac = true;
}
void pulsacyjny::zablokuj()
{
	rysowac = false;
}

bool pulsacyjny::czy_rsyowac()
{
	return rysowac;
}

void pulsacyjny::zmien_kolory(int bonus)
{
	if (lastBonus != bonus)
	{
		lastBonus == bonus;
		if (bonus == 1)
		{

			sprite.setTexture(rs);
			sprite.setTextureRect(IntRect(0, 0, 97, 97));
			frame_Time.restart();
		}
		else if (bonus == 2)
		{

			sprite.setTexture(bs);
			sprite.setTextureRect(IntRect(0, 0, 97, 97));
			frame_Time.restart();
		}
		else if (bonus <= 3)
		{

			sprite.setTexture(gs);
			sprite.setTextureRect(IntRect(0, 0, 97, 97));
			frame_Time.restart();
		}
	}
}
