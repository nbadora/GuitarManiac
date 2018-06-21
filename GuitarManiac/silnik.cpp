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

	//music.openFromFile("dragonforce.wav");
	start_music = false;
	bg_texture.loadFromFile("grafiki/back.png");
	background.setTexture(bg_texture);
	background.setPosition(0, 0);
	menu_texture.loadFromFile("grafiki/back1.png");
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
	for (int i = 0; i < kreski.size(); i++)
	{
		for (int j = i + 1; j < kreski.size(); j++)
		{
			if (kreski[i]->koniecKreski().y < kreski[j]->poczatekKreski().y)
			{
				kreski[j]->correct(-50);
			}
		}
	}
}


void silnik::check_A_button()
{
	bool reset = true;
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
				reset = false;
			}
		}
	}
	if (reset)
	{
		player_one.resetBonus();
	}
}
void silnik::check_S_button()
{
	bool reset = true;
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
				reset = false;
			}
		}
	}
	if (reset)
	{
		player_one.resetBonus();
	}
}
void silnik::check_D_button()
{
	bool reset = true;
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
				reset = false;
			}
		}
	}
	if (reset)
	{
		player_one.resetBonus();
	}
}
void silnik::check_F_button()
{
	bool reset = true;
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
				reset = false;
			}
		}
	}
	if (reset)
	{
		player_one.resetBonus();
	}
}

void silnik::loadTop(gameState &state)
{
	background.setTexture(menu_texture);
	Text text;
	Font font;
	font.loadFromFile("WITCB.ttf");
	text.setCharacterSize(50);
	text.setFont(font);
	text.setPosition(50, 0);
	text.setFillColor(Color::Black);

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
			window.clear();

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
			window.draw(background);
			window.draw(text);
			window.display();
		}
	}
	else
	{
		cout << "Plik z wynikami nie istnieje!";
	}
}


void silnik::nowa_gra(gameState &state)
{
	
	background.setTexture(menu_texture);
	Text text;
	Font font;
	font.loadFromFile("WITCB.ttf");
	text.setCharacterSize(50);
	text.setFont(font);
	text.setFillColor(Color::Black);

	fstream plik;
	plik.open("piosenki.txt", std::fstream::in);
	vector <string*> piosenki;
	if (plik.is_open())
	{
		while (plik.good())
		{
			string tytul;
			plik >> tytul;
			piosenki.push_back(new string(tytul));
		}
		plik.close();

		int wybor = 0;
		while (state == WYBOR_PIOSENKI)
		{
			string tekst = *piosenki[wybor];
			text.setString(tekst);
			text.setPosition(400 - (tekst.size() / 2) * 18, 260);
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
				if (eve.type == eve.KeyPressed)
				{
					if (eve.key.code == Keyboard::Left)
					{
						wybor--;
						if (wybor < 0)
						{
							wybor = piosenki.size() - 1;
						}
					}
					if (eve.key.code == Keyboard::Right)
					{
						wybor++;
						if (wybor >= piosenki.size())
						{
							wybor = 0;
						}
					}
					//ENTER
					if (eve.key.code == Keyboard::Return)
					{
						string path;
						path.append(*piosenki[wybor]);
						player_one.setSong(*piosenki[wybor]);
						path.append(".wav");
						music.openFromFile(path);
						state = MENU;
					}
				}
			}
			window.draw(background);
			window.draw(text);
			window.display();
		}
	}
	else
	{
	//co zrobic gdy pliku nie ma
	}

}

void silnik::nowy_gracz()
{
	background.setTexture(menu_texture);
	string tekst = "Podaj nazwe uzytkownika:";
	string nick;
	Text text;

	Font font;
	font.loadFromFile("WITCB.ttf");
	text.setCharacterSize(60);
	text.setFont(font);
	text.setString(tekst);
	text.setPosition(100, 180);
	text.setFillColor(Color::Black);

	bool good = false;

	while (!good)
	{
		Event eve;
		window.clear();
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

			else if (eve.type == sf::Event::TextEntered)
			{
				if (eve.text.unicode == '\b')
				{
					if (nick.size() > 0)
					{
						nick.erase(nick.size() - 1, 1);
					}
				}
				//ENTER
				else if (eve.text.unicode == '\r')
				{
					//if nick jest dobry to zmien good  na true
					//regex
					cout << "good";
					good = true;
					player_one.setName(nick);
				}
				else if (eve.text.unicode < 128)
				{
					nick += static_cast<char>(eve.text.unicode);
				}
				cout << nick << endl;

			}
		
		}

		window.draw(background);
		text.setPosition(100, 180);
		text.setString(tekst);
		window.draw(text);

		text.setPosition(400-nick.size()*12,240);
		text.setString(nick);
		window.draw(text);

		window.display();


	}
}




void silnik::menu_gry(gameState &state)
{
	background.setTexture(menu_texture);
	string tekst = "Nowa Runda \n  Top 10   \nWyjscie z gry\n";
	Text text;
	Font font;
	font.loadFromFile("WITCB.ttf");
	text.setCharacterSize(60);
	text.setFont(font);
	text.setString(tekst);
	text.setPosition(260, 180);
	text.setFillColor(Color::Black);

	string wsk;
	int pos = 1;
	Text wskaznik;
	wskaznik.setCharacterSize(60);
	wskaznik.setFont(font);
	wskaznik.setFillColor(Color::Black);
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
			window.draw(background);
			window.draw(wskaznik);
			window.draw(text);
			window.display();
		}
	}
}



silnik::~silnik()
{
}


void silnik::zapisz_wynik()
{
	fstream plik;
	plik.open("Top10.txt", std::fstream::in);
	string tekst;
	lista *head = nullptr;
	lista *wsk = nullptr;
	cout << "1\n";
	if (plik.is_open())
	{
		cout << "open666\n";
		//wczytywanie do listy
		for (int i = 0; i < 10; i++)
		{
			string n;
			string p;
			string pkt;
			if (head == nullptr)
			{
				head = new lista();
				plik >> n >> pkt >> p;
				head->nick = n;
				head->piosenka = p;
				head->punkty = atoi(pkt.c_str());
			}
			else
			{
				lista * aux = head;
				head->next = new lista();
				head = head->next;

				plik >> n >> pkt >> p;
				head->nick = n;
				head->piosenka = p;
				head->punkty = atoi(pkt.c_str());

				aux->next = head;
				head->pop = aux;			
			}
			
		}
		
	}
	//dodaje nowy wynik
	head->next = new lista();
	head->next->pop = head;
	head = head->next;
	head->nick = player_one.getName();
	head->piosenka = player_one.getSong();
	head->punkty = player_one.getPoints();
	
	//powrot na poczatek
	wsk = head;
	while (wsk != nullptr)
	{
		head = wsk;
		cout << head->punkty << endl;
		wsk = wsk->pop;
	}

	wsk = head;
	cout << wsk->nick << " " << wsk->punkty << " " << wsk->piosenka << endl;
	lista *aux = head;
	//sortowanie
	while (wsk != nullptr)
	{
		cout << "sort\n";
		aux = wsk->next;
		while (aux != nullptr)
		{
			if (wsk->punkty < aux->punkty)
			{
				string n = wsk->nick;
				string p = wsk->piosenka;
				int pkt = wsk->punkty;
				
				wsk->nick = aux->nick;
				wsk->piosenka = aux->piosenka;
				wsk->punkty = aux->punkty;

				aux->nick = n;
				aux->piosenka = p;
				aux->punkty = pkt;
			}
			aux = aux->next;
		}
		wsk = wsk->next;
	}
	plik.close();
	plik.open("Top10.txt", ios::out | ios::trunc);
	wsk = head;
	while (wsk != nullptr)
	{
		plik << wsk->nick << " " << wsk->punkty << " " << wsk->piosenka << endl;
		cout << wsk->nick << " " << wsk->punkty << " " << wsk->piosenka << endl;
		wsk = wsk->next;
	}
	plik.close();
	while (wsk != nullptr)
	{
		lista * dd = wsk;
		wsk = wsk->pop;
		delete dd;
	}
}

void silnik::start()
{

	background.setTexture(bg_texture);
	Clock zegar;
	Event eve;
	music.play();
	inGame = true;
	while (inGame)
	{
		if (music.getStatus() == Music::Status::Stopped)
		{
			inGame = false;
		}
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

	}
	cout << "zapisz";
	zapisz_wynik();
	cout << "size" << kreski.size();
	/*for (int i = 0; i < kreski.size(); i++)
	{	
		delete kreski[i];
		kreski.erase(kreski.begin() + i);
	}*/
	kreski.clear();
	kreski.shrink_to_fit();
	cout<<"size"<<kreski.size();
}
