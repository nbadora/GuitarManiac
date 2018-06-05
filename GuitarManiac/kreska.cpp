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
		cout << "NADCHODZI KROPKA";
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
		sprite_kreski[i]->move(0, 1);
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
