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
void menu()
{
	cout << "Wybierz: 1 - aby, dodac walute do listy ulubionych"<<endl;
	cout << "         2 - aby, usunac walute z listy ulubionych"<<endl;
	cout << "         3 - aby, wyswietlic kursy walut z konkretnego dnia"<<endl;
	cout << "         4 - aby, wyswietlic kursy z X dni"<<endl;
	cout << "         5 - aby, wyswietlic informacje na temat trendu danej waluty"<<endl;
	cout << "         6 - aby, wyjsc"<<endl;
}
int main()
{
	list<NazwyPlikowNBP> lista_plikow;

	list<string> lista_walut;
	lista_walut.push_back("USD");
	lista_walut.push_back("GBP");
	lista_walut.push_back("EUR");
	//lista_walut.push_back("NOK");
	//lista_walut.push_back("AUD");


	vector<Waluta> tablica_walut;
	list<DataIWaluty> kursy_walut;
	string data;
	string kod_waluty;
	int ilosc_dni;
	int i;
	UI obj;


	menu();
	cin>>i;
	while(i!=6)
	{
		switch (i)
			{
			case 1:
				cout << "Podaj kod waluty, ktora chcesz dodac: ";
				cin>>kod_waluty;
				obj.dodaj_walute_do_listy(lista_walut,kod_waluty);

				break;
			case 2:
				cout << "Podaj kod waluty, ktora chcesz usunac: ";
				cin>>kod_waluty;
				obj.usun_walute_z_listy(lista_walut,kod_waluty);

				break;
			case 3:
				cout << "Podaj date w formacie dd-mm-rr: ";
				cin>>data;
				obj.wyswietl_kursy_walut_z_dnia(lista_plikow,30,kursy_walut,tablica_walut,lista_walut,data);

				break;
			case 4:
				cout << "Podaj z ilu dni wyswietlic informacje: ";
				cin >> ilosc_dni;
				obj.wyswietl_kursy_z_x_dni(lista_plikow,ilosc_dni,kursy_walut,tablica_walut,lista_walut);

				break;
			case 5:
				cout<< "Podaj kod waluty: ";
				cin >> kod_waluty;
				obj.pokaz_czy_wymienic(lista_plikow,30, kursy_walut,tablica_walut,lista_walut,kod_waluty);

				break;
			}
		menu();
		cin >> i;
	}
	cout << "!!!Hello World!!!";
	return 0;
}
