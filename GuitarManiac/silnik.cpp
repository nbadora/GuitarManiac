#include "stdafx.h"
#include "silnik.h"



silnik::silnik()
{
	VideoMode vmode(800, 600);
	Vector2u vec2u(800, 600);
	window.create(vmode, "Raptor", Style::Default);
	window.setFramerateLimit(120);
	
	inGame = true;
	VideoMode video_mode(800, 600);
	window.create(video_mode, "Guitar Maniac", Style::Default);
	window.setFramerateLimit(120);

	srand(time(0));//do losowego generowania

	buttons.push_back(new przycisk("grafiki/redbutton.png", 240, 500));
	buttons.push_back(new przycisk("grafiki/bluebutton.png", 340, 500));
	buttons.push_back(new przycisk("grafiki/greenbutton.png", 440, 500));
	buttons.push_back(new przycisk("grafiki/violetbutton.png", 540, 500));

	music.openFromFile("dragonforce.wav");
	start_music = false;
	
}

void silnik::add_lines()
{
	if (kreski.size() < 6)
	{
		switch (rand() % 4)
		{
		case 0:
		{
			kreski.push_back(new kreska(rand() % 8 + 2,240, rand() % 400 - 800, "grafiki/redcos.png"));
		}
		case 1:
		{
			kreski.push_back(new kreska(rand() % 8 + 2, 340, rand() % 400 - 800, "grafiki/bluecos.png"));
		}
		case 2:
		{
			kreski.push_back(new kreska(rand() % 8 + 2, 440, rand() % 400 - 800, "grafiki/greencos.png"));
		}
		case 3:
		{
			kreski.push_back(new kreska(rand() % 8 + 2, 540, rand() % 400 - 800, "grafiki/violetcos.png"));
		}
		}
	}
}

silnik::~silnik()
{
}

void silnik::start()
{
	Clock zegar;
	Event eve;
	while (inGame)
	{
		while (window.pollEvent(eve))
		{
			if (eve.type == Event::Closed)
			{
				window.close();
			}
			if (eve.type == Event::Resized)
			{
				eve.Resized;
			}
		}

		if (!start_music)
		{
			start_music = true;
			music.play();
		}
		window.clear();

		add_lines();
		for (auto i : buttons)
		{
			window.draw(*i);
		}
		for (int i=0; i< kreski.size();i++)
		{
			kreski[i]->move();
			if (kreski[i]->poza_oknem())
			{
				delete kreski[i];
				kreski.erase(kreski.begin() +i);
			}
		}
		for (auto i : kreski)
		{
			i->rysuj_kreske(&window);
		}
		player_one.wyswietl_punkty(&window);
		
		window.display();

		if (zegar.getElapsedTime().asMilliseconds() > 1000)
		{
			zegar.restart();
			player_one.dodaj_punkty();
		}


	
	}
}
