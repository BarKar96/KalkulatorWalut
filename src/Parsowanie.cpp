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

vector<Waluta> Parsowanie::Parsuj_Plik(string nazwa_pliku_do_sparsowania, string nazwa_pliku_do_zapisu, list<string> lista_walut)
{
	vector<Waluta> tablica_walut;
	fstream plik;
	fstream plik2;
	plik.open(nazwa_pliku_do_sparsowania.c_str(), ios::in);
	plik2.open(nazwa_pliku_do_zapisu.c_str(),ios::out);
	string linia;
	char* linia2;
	string nazwa;
	string nazwa1;
	float kurs_sredni1;
	string przelicznik;
	int przelicznik1;
	string kod_waluty;
	string kurs_sredni;
	size_t znalezione;
	while (!plik.eof())
	{

		getline(plik, linia);
		linia2 = (char*) linia.c_str();
		znajdz_wartosc_xml(linia2,nazwa, "<nazwa_waluty>");
			for (list<string>::iterator it=lista_walut.begin(); it!=lista_walut.end(); it++)
			{
				if ((*it)==nazwa)
				{
					nazwa1=nazwa;
					plik2<<nazwa<<endl;
					getline(plik, linia);
					linia2 = (char*) linia.c_str();
					znajdz_wartosc_xml(linia2,przelicznik, "<przelicznik>");
					plik2<<przelicznik<<endl;
					przelicznik1=atof(przelicznik.c_str());
					getline(plik, linia);
					linia2 = (char*) linia.c_str();
					znajdz_wartosc_xml(linia2,kod_waluty, "<kod_waluty>");
					plik2<<kod_waluty<<endl;
					getline(plik, linia);
					linia2 = (char*) linia.c_str();
					znajdz_wartosc_xml(linia2, kurs_sredni, "<kurs_sredni>");
					znalezione=kurs_sredni.find(",");
					kurs_sredni.replace(znalezione,1,".");
					kurs_sredni1=(float)atof(kurs_sredni.c_str());
					plik2<<kurs_sredni<<endl;
					Waluta nazwa1(nazwa,przelicznik1,kod_waluty,kurs_sredni1);
					tablica_walut.push_back(nazwa1);
				}
				//lista_walut.remove(nazwa);
			}


	}
	plik.close();
	plik2.close();
	return tablica_walut;
}
