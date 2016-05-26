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
	string zapisz_wartosc_xml(string znacznik, string wartosc);
	bool stop;
public:
	Parsowanie();
	virtual ~Parsowanie();
	void parsuj_plik(std::string nazwa_pliku, std::list<string>& kody_walut, std::vector<Waluta>& tablica_walut);
	void pobierz_waluty_z_pliku(list<string> lista_walut, vector<Waluta>& tablica_walut);
	int znajdz_jedna_walute(ifstream& plik, list<string>& kody_walut, vector<Waluta> &wektor_walut);
	void zapis_do_pliku_z_dnia(string name, vector<Waluta> &vector_walut);
	void parsuj_sciezki();
};

#endif /* PARSOWANIE_H_ */
