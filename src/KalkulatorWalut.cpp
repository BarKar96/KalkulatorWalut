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
#include <curl/curl.h>
#include "Pobieranie.h"
using namespace std;

int znajdz_walute(char* linia, std::string &wartosc)
{
	std::string znacznik_poczatek = "<nazwa_waluty>";
	char* wartosc_poczatek = strstr(linia, znacznik_poczatek.c_str());
	wartosc_poczatek = wartosc_poczatek + znacznik_poczatek.length();
	char* wartosc_koniec = strstr(linia, "</nazwa_waluty>");
	if (wartosc_koniec == NULL || wartosc_koniec == wartosc_poczatek)
	{
		cout<<"nie znaleziono szukanej frazy";
		return 0;
	}
	char* slowo = new char[wartosc_koniec-wartosc_poczatek];
	memcpy(slowo, wartosc_poczatek, wartosc_koniec-wartosc_poczatek);
	wartosc = (const char*) slowo;
	cout <<slowo << endl;
	delete[] slowo;
	return wartosc.length();
	//c_str = string --> const char*
	// const char* to na przyklad "napis"

	fstream plik;
	std::string linias;
	getline(plik, linias);
	char *linia2 = (char*) linias.c_str();
}


int main()
{
	 Pobieranie z;
	 z.pobieraniePliku("http://www.nbp.pl/kursy/xml/a075z160419.xml","plik2.txt");





	fstream a;
	fstream b;
	//byle jaka zmiana



	a.open("plik.txt", ios::in);
	b.open("parsowanie.txt", ios::out);

	char tab[200];
	const char *c;

	string linia;
	int i = 0;
	while (!a.eof())
	{
		i++;

		getline(a, linia);
		if (i % 6 == 0)
		{
			if (i != 216)
			{
				c = linia.c_str();
				strcpy(tab, c);

				for (unsigned int i = 20; i < linia.length() - 16; i++)
				{
					cout << tab[i];

				}
				cout << endl;
			}

		}
		if ((i - 1) % 6 == 0)
		{
			if(i!=1)
			{
				c = linia.c_str();
				strcpy(tab, c);

				for (unsigned int i = 19; i < linia.length() - 15; i++)
				{
					cout << tab[i];

				}
				cout << endl;
			}

		}
	    	if((i-2)%6==0)
	    	{
	    		if(i!=2)
	    		{
	    			c = linia.c_str();
	    			strcpy(tab, c);

	    			for (unsigned int i = 18; i < linia.length() - 14; i++)
	    			{
	    				cout << tab[i];

	    			}
	    			cout << endl;
	    		}
	    	}
	    	if((i-3)%6==0)
	    	{
	    		if(i!=3)
	    		{
	    			c = linia.c_str();
	    			strcpy(tab, c);

	    			for (unsigned int i = 19; i < linia.length() - 15; i++)
	    			{
	    				if(tab[i]==',')
	    				{
	    					cout<<".";
	    				}
	    				else
	    					cout << tab[i];
	    			}
	    			cout << endl;
	    		}
	    	}

	}







	    	cout<<"koniec";
	return 0;
}
