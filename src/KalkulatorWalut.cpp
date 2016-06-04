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

	list<string> lista_walut;
	lista_walut.push_back("USD");
	lista_walut.push_back("GBP");
	lista_walut.push_back("EUR");
	lista_walut.push_back("NOK");
	lista_walut.push_back("AUD");
	lista_walut.push_back("HKD");


	vector<Waluta> tablica_walut;

	list<DataIWaluty> kursy_walut;


	UI obj;

	obj.wyswietl_kursy_z_x_dni(lista_plikow,100,kursy_walut,tablica_walut,lista_walut);
	cout << endl;
	obj.wyswietl_kursy_walut_z_dnia(lista_plikow,30,kursy_walut,tablica_walut,lista_walut,"27-05-16");
	cout << endl;
	//obj.linia_trendu(kursy_walut,"AUD");
	cout <<endl<< "!!!koniec!!!";
	return 0;
}
