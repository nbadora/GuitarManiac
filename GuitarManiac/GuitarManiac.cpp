#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include "ball.h"

using namespace sf;
using namespace std;

int main()
{
	/*Music music;
	music.openFromFile("dragonforce.wav");
	Ball ball(70, -1000);
	Ball ball1(120, 0);

	RectangleShape line(Vector2f(800, 5));
	line.setFillColor(Color::Black);
	line.setPosition(0, 500);

	RenderWindow window{ VideoMode(800, 600), "GuitarManiac" };
	window.setFramerateLimit(60);

	Event eve;
	while (window.isOpen())
	{
	window.pollEvent(eve);
	window.clear(Color::White);

	if (eve.type==Event::Closed)
	{
	window.close();
	break;
	}

	if (ball.update())
	{
	music.play();
	}

	if (ball1.update())
	{
	music.play();
	}



	window.draw(line);
	window.draw(ball);
	window.draw(ball1);
	window.display();
	}*/

	/*while(nie wysjscie z gry)
	{switch(enum)
	case a:
	enigne.start
	case b:
	engine menu
	default: 

	itd..
	
	case quit:
	wyjscie z gry na true zamknie petle
	{*/

	//cos nie dziala
	silnik engine;
	engine.start();

	return 0;
}