#include "stdafx.h"
#include "przycisk.h"


przycisk::przycisk(string sciezka, float x, float y)
{
	texture.loadFromFile(sciezka);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setOrigin(37, 37);
	sprite.setPosition(x, y);
	
}


przycisk::~przycisk()
{
}
