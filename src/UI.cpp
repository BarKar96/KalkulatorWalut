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
void UI::dodaj_walute_do_listy(list<string>& lista_walut, string& kod)
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
					cout << j->get_kod_waluty() << "  " << j->get_kurs_sredni()<< " PLN";
					cout << endl;
				}
		}
	}


}
void UI::pokaz_rokowania_na_podstawie_x_dni()
{

}
void UI::pokaz_kursy_z_x_dni(list<DataIWaluty> kursy_walut, int wiersze=30)
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
			for (unsigned int  j=0; j< i->wektor_walut.size()*11+12; j++)
			{
				cout << "-";
			}
			cout << endl;
			cout.width(4);
			cout << left<<"|";
			cout.width(7);
			cout <<left << "DATA";
			cout << "|";

			for (vector<Waluta>::iterator it=i->wektor_walut.begin(); it!=i->wektor_walut.end(); ++it)
			{
				cout << "   ";
				cout.width(7);
				cout <<left << it->get_kod_waluty();
				cout << "|";

			}
			cout << endl;
			for (unsigned int  j=0; j< i->wektor_walut.size()*11+12; j++)
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
			if(licznik2==i->wektor_walut.size())
			{
				cout.width(2);
				cout <<right<<"|";
			}
		}
		licznik++;
		cout << endl;
	}
	for (unsigned int  j=0; j< kursy_walut.begin()->wektor_walut.size()*11+12; j++)
	{
		cout << "-";
	}
	cout << endl;
}
void UI::wyswietl_kursy_z_x_dni(list<NazwyPlikowNBP>& lista_plikow, int x,list<DataIWaluty>& kursy_walut, vector<Waluta>& tablica_walut,list<string>& lista_walut)
{
	Pobieranie pobierak;
	Parsowanie par;
	pobierak.pobierz_sciezki();
	par.parsuj_sciezki();
	pobierak.utworz_liste_plikow(lista_plikow);
	pobierak.pobierz_dane_z_x_dni(x,lista_plikow);
	par.parsuj_x_ostatnich_plikow(kursy_walut,lista_plikow,lista_walut,tablica_walut, x);
	for (vector<Waluta>::iterator it=kursy_walut.begin()->wektor_walut.begin(); it!=kursy_walut.begin()->wektor_walut.end(); ++it)
	{
		cout<<" wyswietl_kursy_z_x_dni kursy walut : "<<it->get_kod_waluty()<<endl;
	}
	pokaz_kursy_z_x_dni(kursy_walut,x);

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
void UI::linia_trendu(list<DataIWaluty>& kursy_walut, string kod_waluty, float& srednia_arytmetyczna, float& wartosc_linii_trendu, float& aktualny_kurs)
{
	int licznik=30;

	float pierwszy_krok=0;
	float srednia_arytmetyczna_t=0;
	float srednia_arytemtyczna_y=0;
		for (list<DataIWaluty>::iterator i = kursy_walut.begin(); i != kursy_walut.end(); i++)
		{

			for (vector<Waluta>::iterator j = i->wektor_walut.begin(); j != i->wektor_walut.end(); ++j)
			{

				if(j->get_kod_waluty()==kod_waluty)
				{
					pierwszy_krok+=(j->get_kurs_sredni()*licznik);
					srednia_arytemtyczna_y+=j->get_kurs_sredni();
					if(licznik==30)
					{
						aktualny_kurs=j->get_kurs_sredni();
					}
				}
			}
			licznik--;
			if(licznik==0)
				break;
		}
	pierwszy_krok=pierwszy_krok/30;
	//cout << pierwszy_krok;
	for (int i=1; i<=30; i++)
	{
		srednia_arytmetyczna_t+=i;
	}
	srednia_arytmetyczna_t/=30;
	//cout <<endl <<  srednia_arytmetyczna_t;
	srednia_arytemtyczna_y/=30;
	//cout << endl << srednia_arytemtyczna_y;
	float pom=srednia_arytemtyczna_y*srednia_arytmetyczna_t;
	float gorna_czesc=pierwszy_krok-pom;
	//cout <<endl<< gorna_czesc;
	////////////////////////////////////////////////
	float tab[30];
	for (int i=0; i<30; i++)
	{
		tab[i]=i+1;
	}

	for (int i=0; i<30; i++)
	{
		tab[i]=tab[i]-srednia_arytmetyczna_t;

	}
	for (int i=0; i<30; i++)
	{
		tab[i]=tab[i]*tab[i];
		//cout << endl << tab[i] << " ";
	}
	float dolna_czesc=0;
	for (int i=0; i<30; i++)
	{
		dolna_czesc+=tab[i];
	}
	dolna_czesc/=30;
	//cout << dolna_czesc;

	float wynik=0;
	//cout << endl << "gorna: "<< gorna_czesc <<endl<< "dolna: "<<dolna_czesc<<endl;
	wynik=(gorna_czesc/dolna_czesc);
	//cout << wynik;
	srednia_arytmetyczna=srednia_arytemtyczna_y;
	wartosc_linii_trendu=wynik;
}
bool UI::czy_wymienic(list<DataIWaluty> kursy_walut, float srednia_arytmetyczna, float wartosc_linii_trendu,float& aktualny_kurs)
{
	if (wartosc_linii_trendu>0 && aktualny_kurs>srednia_arytmetyczna)
	{
		return true;
	}
	else
		return false;
}
void UI::pokaz_czy_wymienic(list<NazwyPlikowNBP>& lista_plikow, int x,list<DataIWaluty>& kursy_walut, vector<Waluta>& tablica_walut,list<string>& lista_walut, string kod_waluty)
{
	Pobieranie pobierak;
	Parsowanie par;
	float srednia_arytmetyczna;
	float trend;
	float aktualny_kurs;
	pobierak.pobierz_sciezki();
	par.parsuj_sciezki();
	pobierak.utworz_liste_plikow(lista_plikow);
	pobierak.pobierz_dane_z_x_dni(30,lista_plikow);
	par.parsuj_x_ostatnich_plikow(kursy_walut,lista_plikow,lista_walut,tablica_walut, 30);
	linia_trendu(kursy_walut,kod_waluty, srednia_arytmetyczna,trend,aktualny_kurs);
	cout << "Aktualny kurs waluty "<<kod_waluty<<" to:  "<<aktualny_kurs<<" PLN"<<endl;
	cout << "Srednia arytmetyczna wahań kursu na podstawie 30 dni to:  "<<srednia_arytmetyczna<<" PLN"<<endl;
	if(czy_wymienic(kursy_walut, srednia_arytmetyczna, trend, aktualny_kurs)==true)
	{
		cout << "Wartosc waluty rosnie o:  "<<trend<<" PLN"<<"  na dzien"<<endl;
	}
	else
	{
		cout << "Wartosc waluty maleje o:  "<<trend<<" PLN"<<"  na dzien"<<endl;
	}

}
void UI::usun_walute_z_listy(list<string>& lista_walut, string& kod)
{

	for (list<string>::iterator i=lista_walut.begin(); i!=lista_walut.end(); i++)
	{
		if ((*i)==kod)
		{
			lista_walut.erase(i);
			break;
		}
	}

}
