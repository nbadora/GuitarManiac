#pragma once

#include <SFML\Graphics.hpp>

using namespace sf;

class Ball : public sf::Drawable
{
public:

	Ball(float x, float y);
	Ball() = delete;
	~Ball() = default;

	bool update();

	float left();
	float right();
	float up();
	float down();

private:
	CircleShape circle;
	 float ballRadius{ 20.0f };	
	 float ballvelocity{ 4.0f };
	 bool changed;

	Vector2f velocity{ 0.0f , ballvelocity };

	void draw(RenderTarget& target, RenderStates state) const override;
};

