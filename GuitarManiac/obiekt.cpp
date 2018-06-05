#include "stdafx.h"
#include "obiekt.h"


obiekt::obiekt()
{
}


obiekt::~obiekt()
{
}

void obiekt::draw(RenderTarget &target, RenderStates state)const
{
	target.draw(this->sprite, state);
}
