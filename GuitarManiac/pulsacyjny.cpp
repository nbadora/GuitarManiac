#include "stdafx.h"
#include "pulsacyjny.h"


pulsacyjny::pulsacyjny(float x, float y)
{
	texture.loadFromFile("grafiki/rseries.png");
	sprite.setTexture(texture);
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
