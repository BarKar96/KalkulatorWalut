/*
 * Parsowanie.cpp
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */

#include "Parsowanie.h"
#include "Waluta.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int Parsowanie::znajdz_wartosc_xml(char* linia, string &wartosc, string fraza_poczatkowa)
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

void Parsowanie::parsuj_plik(string nazwa_pliku_do_sparsowania, string nazwa_pliku_do_zapisu, list<string>& lista_walut,list<string>& lista_znalezionych_walut,list<string>& lista_nieznalezionych_walut, vector<Waluta>& tablica_walut)
{

	fstream plik;
	fstream plik2;
	plik.open(nazwa_pliku_do_sparsowania.c_str(), ios::in);
	plik2.open(nazwa_pliku_do_zapisu.c_str(),ios::out);
	while(tablica_walut.size()!=lista_znalezionych_walut.size())
	{
		znajdz_jedna_walute(plik, lista_walut, lista_nieznalezionych_walut, lista_znalezionych_walut, tablica_walut);
	}
	plik.close();
	plik2.close();
}
int Parsowanie::znajdz_jedna_walute(fstream& plik, list<string>& lista_szukanych_walut, list<string>& lista_nieznalezionych_walut,list<string>& lista_znalezionych_walut, vector<Waluta> &wektor_walut)
{

	int licznik=0;
	string linia;
	char* linia2;
	string nazwa;
	string nazwa_waluty;
	float kurs_sredni1;
	string przelicznik;
	int przelicznik1;
	string kod_waluty;
	string kurs_sredni;
	size_t znalezione;
	while(!plik.eof() || licznik!=4)
	{
		getline(plik, linia);
		linia2 = (char*) linia.c_str();
		if (znajdz_wartosc_xml(linia2,nazwa, "<nazwa_waluty>"))
		{
			nazwa_waluty=nazwa;
			while(find(lista_szukanych_walut.begin(),lista_nieznalezionych_walut.end(),nazwa_waluty)==lista_szukanych_walut.end())
			{
				getline(plik, linia);
				linia2 = (char*) linia.c_str();
				znajdz_wartosc_xml(linia2,nazwa, "<nazwa_waluty>");
				if (plik.eof())
					return 1;
			}
			licznik++;

		}
		else if (znajdz_wartosc_xml(linia2, przelicznik, "<przelicznik>"))
		{
			przelicznik1=atof(przelicznik.c_str());
			licznik++;
		}
		else if (znajdz_wartosc_xml(linia2, kod_waluty, "<kod_waluty>"))
		{
			licznik++;
		}
		else if (znajdz_wartosc_xml(linia2, kurs_sredni, "<kurs_sredni>"))
		{
			kurs_sredni1=(float)atof(kurs_sredni.c_str());
			licznik++;
		}

	}
	if (licznik==4)
	{
		lista_nieznalezionych_walut.remove(nazwa_waluty);
		wektor_walut.push_back(Waluta(nazwa_waluty,przelicznik1,kod_waluty,kurs_sredni1));
		lista_znalezionych_walut.push_back(nazwa_waluty);
		return 0;
	}

	return 1;
}
