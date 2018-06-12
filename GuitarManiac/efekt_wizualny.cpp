#include "stdafx.h"
#include "efekt_wizualny.h"


efekt_wizualny::efekt_wizualny()
{
}


efekt_wizualny::~efekt_wizualny()
{
}

void efekt_wizualny::draw(RenderTarget &target, RenderStates state)const
{
	target.draw(this->sprite, state);
}