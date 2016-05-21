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
#include <string>
#include <sstream>
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

Parsowanie::Parsowanie(): stop(false){
	// TODO Auto-generated constructor stub

}

Parsowanie::~Parsowanie() {
	// TODO Auto-generated destructor stub
}

void Parsowanie::parsuj_plik(string nazwa_pliku, list<string>& kody_walut, vector<Waluta>& tablica_walut)
{

	ifstream plik;
	char zmienna[255];
	plik.open(nazwa_pliku.c_str());
	while(kody_walut.size()!=0 && !stop)
	{
		//cout<<"wykonuje petle"<<endl;
		znajdz_jedna_walute(plik, kody_walut, tablica_walut);
	}
	plik.close();
}

int Parsowanie::znajdz_jedna_walute(ifstream& plik, list<string>& kody_walut, vector<Waluta> &wektor_walut)
{
	char linia[255];
	plik.getline(linia, 255);
	int licznik=0;
	std::string nazwa_waluty;
	std::string wartosc;
	float kurs_sredni1;
	float przelicznik1;
	string kod_waluty;
	while(!plik.eof() && licznik!=15)
	{
		wartosc.clear();
		plik.getline(linia, 255);
		if (znajdz_wartosc_xml(linia, wartosc, "<nazwa_waluty>"))
		{
			nazwa_waluty=wartosc;
			licznik=licznik | 1;

		}
		else if (znajdz_wartosc_xml(linia, wartosc, "<przelicznik>"))
		{
			przelicznik1=atof(wartosc.c_str());
			licznik=licznik | 2;
		}
		else if (znajdz_wartosc_xml(linia, wartosc, "<kod_waluty>"))
		{
			if(find(kody_walut.begin(),kody_walut.end(),wartosc)!=kody_walut.end())
			{

				kod_waluty = wartosc;
				licznik=licznik | 4;
			}

		}
		else if (znajdz_wartosc_xml(linia, wartosc, "<kurs_sredni>"))
		{
			wartosc.replace(wartosc.find(","),1,".");
			kurs_sredni1=(float)atof(wartosc.c_str());
			if ((licznik & 4) == 4)
			{
				//cout<<wartosc<<endl;
				licznik=licznik | 8;

			}
		}

	}
	if (licznik==15)
	{
		kody_walut.remove(nazwa_waluty);
		//cout<<"znalazlem "<<nazwa_waluty<<" "<<kod_waluty<<" "<<kurs_sredni1<<" "<<przelicznik1<<endl;
		wektor_walut.push_back(Waluta(nazwa_waluty,przelicznik1,kod_waluty ,kurs_sredni1));
		return 0;
	}
	if(plik.eof())
	{
		this->stop=true;
	}
	return 1;
}

string Parsowanie::zapisz_wartosc_xml(string znacznik, string wartosc)
{
	string wynik= znacznik;
	wynik.append(wartosc);
	wynik.append(znacznik.insert(1,"/"));
	return wynik;
}

string to_string(float numer)
{
	std::ostringstream ss;
	ss << numer;
	std::string s(ss.str());
	return s;
}

void Parsowanie::zapis_do_pliku_z_dnia(string name, vector<Waluta>& vector_walut)
{
	ofstream plik;
	plik.open(name.c_str());
	for (int i=0; i<vector_walut.size(); ++i)
	{
		plik<<zapisz_wartosc_xml("<nazwa_waluty>",vector_walut.at(i).get_nazwa_waluty())<<endl;
		plik<<zapisz_wartosc_xml("<kod_waluty>",vector_walut.at(i).get_kod_waluty())<<endl;
		plik<<zapisz_wartosc_xml("<przelicznik>", to_string(vector_walut.at(i).get_przelicznik()))<<endl;
		plik<<zapisz_wartosc_xml("<kurs_sredni>", to_string(vector_walut.at(i).get_kurs_sredni()))<<endl;
		plik<<endl;
	}
	plik.close();

}
void Parsowanie::parsuj_sciezki()
{


	string tekst;
	ifstream i("kursy.txt");
	ofstream o("sparsowane_kursy.txt");
	i>>tekst;
	while(!i.eof() && tekst.length()>0)
	{

		if(tekst[0]=='a')
		{
			o<<tekst<<endl;
		}
		i>>tekst;
	}


	i.close();
	o.close();
}
