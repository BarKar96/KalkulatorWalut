/*
 * UI.cpp
 *
 *  Created on: May 24, 2016
 *      Author: bartek
 */

#include "UI.h"
#include "Waluta.h"
#include "Pobieranie.h"
#include "Parsowanie.h"
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
void UI::pokaz_aktualne_kursy(list<DataIWaluty> kursy_walut)
{
	list<DataIWaluty>::iterator i=kursy_walut.begin();
	for (vector<Waluta>::iterator j=i->wektor_walut.begin(); j!=i->wektor_walut.end(); ++j)
	{
		cout << j->get_kod_waluty() << "  " << j->get_kurs_sredni();
		cout << endl;
	}

}
void UI::dodaj_walute_do_listy(list<string>& lista_walut, string kod)
{
	lista_walut.push_back(kod);
}
void UI::pokaz_waluty_z_dnia(list<DataIWaluty> kursy_walut,string data)
{
	int licznik=0;
	for(list<DataIWaluty>::iterator i=kursy_walut.begin(); i!=kursy_walut.end(); i++)
	{

		if(licznik!=0)
			{
				break;
			}
		if (i->data==data)
		{
			licznik++;
			for (vector<Waluta>::iterator j=i->wektor_walut.begin(); j!=i->wektor_walut.end(); ++j)
				{
					cout << j->get_kod_waluty() << "  " << j->get_kurs_sredni();
					cout << endl;
				}
		}
	}


}
void UI::pokaz_rokowania_na_podstawie_x_dni()
{

}
void UI::pokaz_kursy_z_x_dni(list<DataIWaluty> kursy_walut, list<string> lista_walut, int wiersze=30)
{
	//cout <<"kursy z x dni";
	string dzien;
	string miesiac;
	string rok;
	int licznik=0;
	unsigned int licznik2=0;
	vector<Waluta>::iterator pom;
	for (list<DataIWaluty>::iterator i = kursy_walut.begin(); i != kursy_walut.end(); i++)
	{
		licznik2=0;
		pom=i->wektor_walut.begin();
		if (licznik==wiersze)
		{
			break;
		}
		if (licznik==0)
		{
			for (unsigned int i=0; i<lista_walut.size()*11+12; i++)
			{
				cout << "-";
			}
			cout << endl;
			cout.width(4);
			cout << left<<"|";
			cout.width(7);
			cout <<left << "DATA";
			cout << "|";

			for (unsigned int i=0; i<lista_walut.size(); i++)
			{
				cout << "   ";
				cout.width(7);
				cout <<left << pom->get_kod_waluty();
				cout << "|";
				pom++;
			}
			cout << endl;
			for (unsigned int i=0; i<lista_walut.size()*11+12; i++)
			{
				cout << "-";
			}
			cout << endl;
		}
		dzien=i->data.substr(0,2);
		miesiac=i->data.substr(2,2);
		rok=i->data.substr(4,2);
		cout <<"| "<<rok<<"-"<<miesiac<<"-"<<dzien;

		for (vector<Waluta>::iterator j = i->wektor_walut.begin(); j != i->wektor_walut.end(); ++j)
		{
			licznik2++;

			cout <<" |  ";
			cout.width(7);
			cout << left << j->get_kurs_sredni();
			if(licznik2==lista_walut.size())
			{
				cout.width(2);
				cout <<right<<"|";
			}
		}
		licznik++;
		cout << endl;
	}
	for (unsigned int i=0; i<lista_walut.size()*11+12; i++)
	{
		cout << "-";
	}
}
void UI::wyswietl_kursy_z_x_dni(list<NazwyPlikowNBP>& lista_plikow, int x,list<DataIWaluty>& kursy_walut, vector<Waluta>& tablica_walut,list<string>& lista_walut)
{
	Pobieranie pobierak;
	Parsowanie par;
	pobierak.pobierz_sciezki();
	par.parsuj_sciezki();
	pobierak.utworz_liste_plikow(lista_plikow);
	pobierak.pobierz_dane_z_x_dni(x,lista_plikow);
	par.parsuj_x_ostatnich_plikow(kursy_walut,lista_plikow,lista_walut,tablica_walut);
	pokaz_kursy_z_x_dni(kursy_walut,lista_walut,x);

}
void UI::wyswietl_kursy_walut_z_dnia(list<NazwyPlikowNBP>& lista_plikow, int x,list<DataIWaluty>& kursy_walut, vector<Waluta>& tablica_walut,list<string>& lista_walut,string data)
{
	string dzien;
	string miesiac;
	string rok;
	cout << "kursy walut z dnia: " <<data<<endl;
	dzien = data.substr(0, 2);
	miesiac = data.substr(3, 2);
	//cout << miesiac;
	rok = data.substr(6, 2);
	data=rok+miesiac+dzien;
	Pobieranie pobierak;
	Parsowanie par;

	pobierak.pobierz_sciezki();
	par.parsuj_sciezki();

	pobierak.utworz_liste_plikow(lista_plikow);

	pobierak.pobierz_dane_z_ostatniego_miesiaca(miesiac,lista_plikow);

	par.parsuj_z_miesiaca(kursy_walut,lista_plikow,lista_walut,tablica_walut,miesiac);
	pokaz_waluty_z_dnia(kursy_walut,data);

}
