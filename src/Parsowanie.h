/*
 * Parsowanie.h
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */

#ifndef PARSOWANIE_H_
#define PARSOWANIE_H_
#include <iostream>
#include "Waluta.h"
#include <cstring>
#include <list>
#include <vector>
#include <string>
using namespace std;
class Parsowanie
{
private:
	int znajdz_wartosc_xml(char* linia, string &wartosc, string fraza_poczatkowa);
public:
	Parsowanie();
	virtual ~Parsowanie();
	void parsuj_plik(std::string nazwa_pliku_do_sparsowania,std::string nazwa_pliku_do_zapisu, std::list<string>& lista_walut,std::list<string> &lista_znalezionych_walut,std::list<string>&lista_nieznalezionych_walut, std::vector<Waluta>& tablica_walut);
	void pobierz_waluty_z_pliku(list<string> lista_walut, vector<Waluta>& tablica_walut);
	int znajdz_jedna_walute(fstream& plik, list<string>& lista_szukanych_walut, list<string>& lista_nieznalezionych_walut,list<string>& lista_znalezionych_walut, vector<Waluta> &wektor_walut);
};

#endif /* PARSOWANIE_H_ */
