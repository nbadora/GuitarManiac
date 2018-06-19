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

void silnik::loadTop(gameState &state)
{
	Text text;
	Font font;
	font.loadFromFile("WITCB.ttf");
	text.setCharacterSize(50);
	text.setFont(font);
	text.setPosition(50, 0);
	text.setFillColor(Color::White);

	fstream plik;
	plik.open("Top10.txt", std::fstream::in);
	string tekst;
	if (plik.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			string s;
			tekst.append(to_string(i + 1));
			tekst.append(".");
			plik >> s;
			tekst.append(s);
			tekst.append(" ");

			plik >> s;
			tekst.append(s);
			tekst.append(" ");

			plik >> s;
			tekst.append(s);
			tekst.append("\n");
		}
		plik.close();
		while (state == NAJLEPSI_GRACZE)
		{
			text.setString(tekst);
			window.clear(Color::Black);

			Event eve;
			window.clear(Color::Black);
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
				if (eve.type == Event::KeyPressed && eve.key.code == Keyboard::Return)
				{
					state = MENU;
				}
			}
			window.draw(text);
			window.display();
		}
	}
	else
	{
		cout << "Plik z wynikami nie istnieje!";
	}
}

void silnik::menu_gry(gameState &state)
{
	string tekst = "Nowa Runda \n  Top 10   \nWyjscie z gry\n";
	Text text;
	Font font;
	font.loadFromFile("WITCB.ttf");
	text.setCharacterSize(60);
	text.setFont(font);
	text.setString(tekst);
	text.setPosition(260, 180);
	text.setFillColor(Color::White);

	string wsk;
	int pos = 1;
	Text wskaznik;
	wskaznik.setCharacterSize(60);
	wskaznik.setFont(font);
	wskaznik.setFillColor(Color::White);
	while (state == MENU)
	{
		Event eve;
		window.clear(Color::Black);
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
			if (eve.type == eve.KeyPressed)
			{
				if (eve.key.code == Keyboard::Down)
				{
					pos++;
				}
				if (eve.key.code == Keyboard::Up)
				{
					pos--;
				}
				//ENTER
				if (eve.key.code == Keyboard::Return)
				{
					if (pos == 1)
					{
						state = WYBOR_PIOSENKI;
						//wybr piosenki + nazwa gracza
					}
					if (pos == 2)
					{
						state = NAJLEPSI_GRACZE;
						//top 10
					}
					if (pos == 3)
					{
						state = WYJSCIE;
						//wyjscie
					}
				}
			}
			//pozycja wskaznika
			if (pos <= 1)
			{
				pos = 1;
				wsk.clear();
				wsk.append(">           <");
				wskaznik.setString(wsk);
				wskaznik.setPosition(215, 180);
			}
			else if (pos == 2)
			{
				wsk.clear();
				wsk.append(">      <");
				wskaznik.setString(wsk);
				wskaznik.setPosition(280, 250);
			}
			else if (pos >= 3)
			{
				pos = 3;
				wsk.clear();
				wsk.append(">           <");
				wskaznik.setString(wsk);
				wskaznik.setPosition(215, 320);
			}
			window.draw(wskaznik);
			window.draw(text);
			window.display();
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
