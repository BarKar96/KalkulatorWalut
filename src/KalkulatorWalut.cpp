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
	lista_walut.push_back("USD");
	lista_walut.push_back("GBP");
	lista_walut.push_back("EUR");
	lista_walut.push_back("NOK");
	Parsowanie w;
	vector<Waluta> tablica_walut;
	list<string> kody_walut_pom=lista_walut;

	std::cout<<"lista walut pom"<<kody_walut_pom.size()<<endl;
	w.parsuj_plik("plik.txt", kody_walut_pom, tablica_walut);
	w.zapis_do_pliku_z_dnia("wyniki.txt", tablica_walut);
	for (unsigned int i=0; i<tablica_walut.size(); i++)
	{
		cout << tablica_walut[i].get_nazwa_waluty() <<" "<< tablica_walut[i].get_kurs_sredni()<<endl;
	}
	cout << "!!!Program has ended with exit 0!!!!";
	return 0;
}
