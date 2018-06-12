#pragma once
#include "efekt_wizualny.h"

class pulsacyjny :public efekt_wizualny
{

public:
	virtual void next_frame() override;
	pulsacyjny(float x, float y);
	~pulsacyjny();
};

