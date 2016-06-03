/*
 * UI.cpp
 *
 *  Created on: May 24, 2016
 *      Author: bartek
 */

#include "UI.h"
#include "Waluta.h"
#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include "NazwyPlikowNBP.h"
#include <fstream>
using namespace std;
UI::UI() {
	// TODO Auto-generated constructor stub

}

UI::~UI() {
	// TODO Auto-generated destructor stub
}
void UI::pokaz_aktualne_kursy(list<vector<Waluta> > lista_wektorow)
{
	list<vector<Waluta> >::iterator i=lista_wektorow.end();
	for (vector<Waluta>::iterator j=i->begin(); j!=i->end(); ++j)
	{
		cout << j->get_kod_waluty() << "  " << j->get_kurs_sredni();
		cout << endl;
	}
}
void UI::dodaj_walute_do_listy(list<string>& lista_walut, string kod)
{
	lista_walut.push_back(kod);
}
void UI::pokaz_waluty_z_dnia(list<vector<Waluta> > lista_wektorow, list<NazwyPlikowNBP> lista_plikow, string data)
{
	int licznik=0;
	for(list<NazwyPlikowNBP>::reverse_iterator i=lista_plikow.rbegin(); i!=lista_plikow.rend(); i++)
	{
		licznik++;
		fstream plik;
		if (i->pobierz_date()==data)
		{
			break;
		}
	}
	int licznik2=0;
	list<vector<Waluta> >::iterator i=lista_wektorow.end();
	for (vector<Waluta>::iterator j=i->begin(); j!=i->end(); ++j)
	{
		licznik++;
			if (licznik2==licznik)
			{
				cout << j->get_kod_waluty() << "  " << j->get_kurs_sredni();
						cout << endl;
			}

	}
}
void UI::pokaz_rokowania_na_podstawie_x_dni()
{

}
