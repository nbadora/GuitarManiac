#include "stdafx.h"
#include "silnik.h"




silnik::silnik()
{
	
	inGame = true;
	VideoMode video_mode(800, 600);
	window.create(video_mode, "Guitar Maniac", Style::Default);
	window.setFramerateLimit(120);

	srand(time(NULL));//do losowego generowania

	/*buttons.push_back(new przycisk("grafiki/redbutton.png", 250, 500));
	buttons.push_back(new przycisk("grafiki/bluebutton.png", 350, 500));
	buttons.push_back(new przycisk("grafiki/greenbutton.png", 450, 500));
	buttons.push_back(new przycisk("grafiki/violetbutton.png", 550, 500));*/

	music.openFromFile("dragonforce.wav");
	start_music = false;
	bg_texture.loadFromFile("grafiki/back.png");
	background.setTexture(bg_texture);
	background.setPosition(0, 0);
	//background.setTextureRect(IntRect(0, 0, 800, 600));

	music.setVolume(5);

	for (int i = 0; i < 4; i++)
	{
		pulsacyjny *wsk = new pulsacyjny(250 + i * 100, 500);
		efekty_pulasacyjne.push_back(*wsk);
	}

	
}

void silnik::add_lines()
{
	if (kreski.size() < 6)
	{
		switch (rand() % 4)
		{
		case 0:
		{
			kreski.push_back(new kreska(rand() % 8 + 2,250, rand() % 400 - 800, "grafiki/redcos.png"));
		}
		case 1:
		{
			kreski.push_back(new kreska(rand() % 8 + 2, 350, rand() % 400 - 800, "grafiki/bluecos.png"));
		}
		case 2:
		{
			kreski.push_back(new kreska(rand() % 8 + 2, 450, rand() % 400 - 800, "grafiki/greencos.png"));
		}
		case 3:
		{
			kreski.push_back(new kreska(rand() % 8 + 2, 550, rand() % 400 - 800, "grafiki/violetcos.png"));
		}
		}
	}
}


void silnik::check_A_button()
{
	for (auto i : kreski)
	{
		if (i->poczatekKreski().x == 250)	//szuka kreski na polu A
		{
			i->odblokuj_punkty();			//pozwala dodawac punkty
			if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)	//sprawdza czy kreska jest na lini do klikania
			{
				if (i->przyznaj_punkty(player_one))		//przynaje punkty jesli gracz trzyma odp. klawisz
				{
					efekty_pulasacyjne[0].odblokuj();
				}
			}
		}
	}
}
void silnik::check_S_button()
{
	for (auto i : kreski)
	{
		if (i->poczatekKreski().x == 350)
		{
			i->odblokuj_punkty();
			if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
			{
				if (i->przyznaj_punkty(player_one))		//przynaje punkty jesli gracz trzyma odp. klawisz
				{
					efekty_pulasacyjne[1].odblokuj();
				}
			}
		}
	}
}
void silnik::check_D_button()
{
	for (auto i : kreski)
	{
		if (i->poczatekKreski().x == 450)
		{
			i->odblokuj_punkty();
			if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
			{
				if (i->przyznaj_punkty(player_one))		//przynaje punkty jesli gracz trzyma odp. klawisz
				{
					efekty_pulasacyjne[2].odblokuj();
				}
			}
		}
	}
}
void silnik::check_F_button()
{
	for (auto i : kreski)
	{
		if (i->poczatekKreski().x == 550)
		{
			i->odblokuj_punkty();
			if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
			{
				if (i->przyznaj_punkty(player_one))		//przynaje punkty jesli gracz trzyma odp. klawisz
				{
					efekty_pulasacyjne[3].odblokuj();
				}
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
	music.play();
	while (inGame)
	{
		window.clear();	// czysci okno
		window.draw(background); //rysuje tlo

		//sprawdza czy ma rysowac efekty
		//korzystamy z iteratora it
		for (vector <pulsacyjny>::iterator it = efekty_pulasacyjne.begin(); it != efekty_pulasacyjne.end(); it++)
		{
			it->zmien_kolory(player_one.getBonus());
			if (it->czy_rsyowac())
			{
				window.draw(*it);//rysuje efekt
				it->zablokuj();//blokuje rysowanie, bedzie odblokowane jesli dalej trzymamy klawisz
			}
			it->next_frame();
		}

	



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
						if (i->poczatekKreski().x == 250)
						{
							if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
							{
								i->blokuj_punkty(player_one);
							}
						}
					}
				}
				else if (eve.key.code == Keyboard::S)
				{
				
					for (auto i : kreski)
					{
						if (i->poczatekKreski().x == 350)
						{
							if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
							{
								i->blokuj_punkty(player_one);
							}
						}
					}
				}
				else if (eve.key.code == Keyboard::D)
				{
					for (auto i : kreski)
					{
						if (i->poczatekKreski().x == 450)
						{
							if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
							{
								i->blokuj_punkty(player_one);
							}
						}
					}
				}
				else if (eve.key.code == Keyboard::F)
				{
					for (auto i : kreski)
					{
						if (i->poczatekKreski().x == 550)
						{
							if (i->poczatekKreski().y >= 500 && i->koniecKreski().y <= 500)
							{
								i->blokuj_punkty(player_one);
							}
						}
					}
				}
			}
		}
		//wywoluje odpowiednia metode w zaleznosci od trzymanego klawisza
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

		//WYCISZANIE PIOSENEK--------------------------------------
		if (player_one.returnReset())
		{
			player_one.setResetFlag();
			music.setVolume(1);
			muteTime.restart();
		}
		if (muteTime.getElapsedTime().asMilliseconds() > 500)
		{
			music.setVolume(10);
		}
		//----------------------------------------------------------

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
