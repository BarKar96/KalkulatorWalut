//============================================================================
// Name        : KalkulatorWalut.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <list>
#include <curl/curl.h>
#include "Pobieranie.h"
#include "Parsowanie.h"
#include "NazwyPlikowNBP.h"
#include "UI.h"
using namespace std;

int main()
{
	list<NazwyPlikowNBP> lista_plikow;
	Pobieranie z;
//	Parsowanie a;
//
//
//
//	z.pobierz_sciezki();
//	a.parsuj_sciezki();
	z.utworz_liste_plikow(lista_plikow);
//	cout.flush();
//	z.pobierz_dane_z_x_dni(5,lista_plikow);
//	z.pobierz_dane_z_ostatniego_miesiaca("03",lista_plikow);
	list<string> lista_walut;
	lista_walut.push_back("USD");
	lista_walut.push_back("GBP");
	lista_walut.push_back("EUR");
	lista_walut.push_back("NOK");
	Parsowanie w;
	vector<Waluta> tablica_walut;

	list<vector<Waluta> > lista_wektorow;
//	w.parsuj_plik("plik.txt", kody_walut_pom, tablica_walut);
//	w.zapis_do_pliku_z_dnia("wyniki.txt", tablica_walut);
//	for (unsigned int i=0; i<tablica_walut.size(); i++)
//	{
//		cout << tablica_walut[i].get_nazwa_waluty() <<" "<< tablica_walut[i].get_kurs_sredni()<<endl;
//	}
	//cout << " 1";
//	w.parsuj_30_ostatnich_plikow(lista_wektorow,lista_plikow,lista_walut,tablica_walut);
	//cout << " 2";

//	for (list<vector<Waluta> >::iterator i=lista_wektorow.begin(); i!=lista_wektorow.end(); i++)
//	{
//
//		for (vector<Waluta>::iterator j=i->begin(); j!=i->end(); ++j)
//		{
//
//			cout<< (*j).get_kod_waluty()<<" "<< j->get_kurs_sredni()<<endl ;
//
//			cout.flush();
//		}
//		cout << endl;
//		cout.flush();
//	}
//	UI klasa;
//	klasa.dodaj_walute_do_listy(lista_walut, "AUD");
//	w.parsuj_30_ostatnich_plikow(lista_wektorow,lista_plikow,lista_walut,tablica_walut);
//	klasa.pokaz_aktualne_kursy(lista_wektorow);
//	cout << endl << endl;
//	klasa.pokaz_waluty_z_dnia(lista_wektorow, lista_plikow, "160524");
	cout << "!!!Program has ended with exit 0!!!!";
//	cout.flush();
	return 0;
}
