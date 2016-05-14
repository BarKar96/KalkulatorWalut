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
using namespace std;

int main()
{
	list<string> lista_walut;
	lista_walut.push_back("kuna (Chorwacja)");
	lista_walut.push_back("dolar australijski");
	lista_walut.push_back("euro");
	lista_walut.push_back("funt szterling");
	lista_walut.push_back("korona czeska");
	lista_walut.push_back("korona szwedzka");
	lista_walut.push_back("lira turecka");
	lista_walut.push_back("rubel rosyjski");
	lista_walut.push_back("hrywna (Ukraina)");
	lista_walut.push_back("jen (Japonia)");

	Parsowanie w;
	vector<Waluta> tablica_walut;
	list<string> lista_znalezionych_walut;
	list<string> lista_nieznalezionych_walut=lista_walut;

	w.parsuj_plik("plik.txt","plik2.txt",lista_walut,lista_znalezionych_walut, lista_nieznalezionych_walut,tablica_walut);
	for (unsigned int i=0; i<tablica_walut.size(); i++)
	{
		cout << tablica_walut[i].get_nazwa_waluty() <<" "<< tablica_walut[i].get_kurs_sredni()<<endl;
	}
	cout << "!!!Hello World!!!!";
	return 0;
}
