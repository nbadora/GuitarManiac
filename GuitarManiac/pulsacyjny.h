#pragma once
#include "efekt_wizualny.h"
#include <SFML/Graphics.hpp>

class pulsacyjny :public efekt_wizualny
{
	bool rysowac = false;
	 Texture rs;
	 Texture bs;
	 Texture gs;
	
	int lastBonus = 1;
public:
	
	virtual void next_frame() override;
	pulsacyjny(float x, float y);
	void odblokuj();
	void zablokuj();
	~pulsacyjny();
	bool czy_rsyowac();
	void zmien_kolory(int bonus);

	
};

