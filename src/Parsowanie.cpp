/*
 * Parsowanie.cpp
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */

#include "Parsowanie.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int znajdz_wartosc_xml(char* linia, string &wartosc, string fraza_poczatkowa)
{
	string fraza_koncowa=fraza_poczatkowa;
	fraza_koncowa.insert(1,"/");
	wartosc.clear();
	string znacznik_poczatek = fraza_poczatkowa;
	char* wartosc_poczatek = strstr(linia, znacznik_poczatek.c_str());
	wartosc_poczatek = wartosc_poczatek + znacznik_poczatek.length();
	char* wartosc_koniec = strstr(linia, fraza_koncowa.c_str());
	if (wartosc_koniec == NULL || wartosc_koniec == wartosc_poczatek)
	{
		//cout<<"nie znaleziono szukanej frazy";
		return 0;
	}
	int dlugosc=wartosc_koniec-wartosc_poczatek;
	char* slowo = new char[dlugosc+1];
	memcpy(slowo, wartosc_poczatek, dlugosc);
	slowo[dlugosc]='\0';
	wartosc = (const char*) slowo;
	//	cout<<wartosc_koniec-wartosc_poczatek;
	delete[] slowo;
	return wartosc.length();
}

Parsowanie::Parsowanie() {
	// TODO Auto-generated constructor stub

}

Parsowanie::~Parsowanie() {
	// TODO Auto-generated destructor stub
}

void Parsowanie::Parsuj_Plik(string nazwa_pliku_do_sparsowania, string nazwa_pliku_do_zapisu)
{
	fstream plik;
	fstream plik2;
	plik.open(nazwa_pliku_do_sparsowania.c_str(), ios::in);
	plik2.open(nazwa_pliku_do_zapisu.c_str(),ios::out);
	string linia;
	char* linia2;
	string wartosc;
	size_t znalezione;
	while (!plik.eof())
	{

		getline(plik, linia);
		linia2 = (char*) linia.c_str();
		if (znajdz_wartosc_xml(linia2,wartosc, "<nazwa_waluty>"))
		{
			plik2<<wartosc<<endl;
			//cout<<wartosc<<endl;
		}
		else if (znajdz_wartosc_xml(linia2,wartosc, "<przelicznik>"))
		{
			plik2<<wartosc<<endl;
			//cout<<wartosc<<endl;
		}
		else if (znajdz_wartosc_xml(linia2,wartosc, "<kod_waluty>"))
		{
			plik2<<wartosc<<endl;
			//cout <<wartosc<<endl;
		}
		else if(znajdz_wartosc_xml(linia2, wartosc, "<kurs_sredni>"))
		{

			znalezione=wartosc.find(',');
			wartosc[znalezione]='.';
			plik2<<wartosc<<endl;

			//cout << wartosc << endl;
		}
	}
	plik.close();
	plik2.close();
}
