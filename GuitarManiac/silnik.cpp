#include "stdafx.h"
#include "silnik.h"



silnik::silnik()
{
	
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

void silnik::check_A_button()
{
	for (auto i : kreski)
	{
		if (i->poczatekKreski().x == 240)
		{
			i->odblokuj_punkty();
			if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
			{
				i->przyznaj_punkty(player_one);
			}
		}
	}
}
void silnik::check_S_button()
{
	for (auto i : kreski)
	{
		if (i->poczatekKreski().x == 340)
		{
			i->odblokuj_punkty();
			if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
			{
				i->przyznaj_punkty(player_one);
			}
		}
	}
}
void silnik::check_D_button()
{
	for (auto i : kreski)
	{
		if (i->poczatekKreski().x == 440)
		{
			i->odblokuj_punkty();
			if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
			{
				i->przyznaj_punkty(player_one);
			}
		}
	}
}
void silnik::check_F_button()
{
	for (auto i : kreski)
	{
		if (i->poczatekKreski().x == 540)
		{
			i->odblokuj_punkty();
			if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
			{
				i->przyznaj_punkty(player_one);
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

		//event jest potrzebny by okno prawidlowo dzialalo + resize okna
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
			//czy gracz puscil klawisz
			if (eve.type == eve.KeyReleased)
			{
				if (eve.key.code == Keyboard::A)
				{
					for (auto i : kreski)
					{
						if (i->poczatekKreski().x == 240)
						{
							if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
							{
								i->blokuj_punkty();
							}
						}
					}
				}
				else if (eve.key.code == Keyboard::S)
				{
					for (auto i : kreski)
					{
						if (i->poczatekKreski().x == 340)
						{
							if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
							{
								i->blokuj_punkty();
							}
						}
					}
				}
				else if (eve.key.code == Keyboard::D)
				{
					for (auto i : kreski)
					{
						if (i->poczatekKreski().x == 440)
						{
							if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
							{
								i->blokuj_punkty();
							}
						}
					}
				}
				else if (eve.key.code == Keyboard::F)
				{
					for (auto i : kreski)
					{
						if (i->poczatekKreski().x == 540)
						{
							if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
							{
								i->blokuj_punkty();
							}
						}
					}
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::A))
		{
			check_A_button();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::S))
		{
			check_S_button();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D))
		{
			check_D_button();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::F))
		{
			check_F_button();
		}

		window.clear(Color::White);	// czysci okno

		add_lines();

		//rysuje przyciski
		for (auto i : buttons)
		{
			window.draw(*i);
		}
		//usuwa kresi gdy sa poza oknem
		for (int i=0; i< kreski.size();i++)
		{
			kreski[i]->move();
			if (kreski[i]->poza_oknem())
			{
				delete kreski[i];
				kreski.erase(kreski.begin() +i);
			}
		}
		//rysuje pozostale kreski
		for (auto i : kreski)
		{
			i->rysuj_kreske(&window);
		}
		//wyswietla aktualne punkty
		player_one.wyswietl_punkty(&window);
		
		//wyswietla okno
		window.display();

		//dodaje punkty bez przerwy
		/*if (zegar.getElapsedTime().asMilliseconds() > 1000)
		{
			zegar.restart();
			player_one.dodaj_punkty();
		}*/
	}
}
