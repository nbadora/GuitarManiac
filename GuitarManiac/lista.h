#pragma once

#include <iostream>
using namespace std;

struct lista
{
	lista *pop = nullptr;
	lista *next = nullptr;
	string nick;
	string piosenka;
	int punkty;

};