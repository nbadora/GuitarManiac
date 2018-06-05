#include "stdafx.h"
#include "Ball.h"
#include <iostream>

using namespace std;
using namespace sf;

Ball::Ball(float x, float y)
{
	circle.setPosition(x, y);
	circle.setRadius(this->ballRadius);
	circle.setFillColor(Color::Blue);
	circle.setOrigin(this->ballRadius, this->ballRadius);
	changed = 0;
}

void Ball::draw(RenderTarget& target, RenderStates state) const 
{
	target.draw(this->circle, state);
}

bool Ball::update()
{
	circle.move(this->velocity);

	if (this->down() > (450) && this->down() < (530) && Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		circle.setFillColor(Color::Magenta);
		changed = 1;
		return true;
	}	
	else if (this->down() > (530)&&!changed)
	{
		circle.setFillColor(Color::Green);
		return false;
	}
	return false;
}

float Ball::down()
{
	return this->circle.getPosition().y + circle.getRadius();
}