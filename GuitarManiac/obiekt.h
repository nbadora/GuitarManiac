#pragma once
#include "stdafx.h"
using namespace std;
using namespace sf;

class obiekt:public Drawable
{
protected:
	Texture texture;
	Sprite sprite;
public:
	void draw(RenderTarget &target, RenderStates state)const override;
	
	obiekt();
	~obiekt();
};

