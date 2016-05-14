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
using namespace std;
class Parsowanie
{
private:
	int znajdz_wartosc_xml(char* linia, string &wartosc, string fraza_poczatkowa);
public:
	Parsowanie();
	virtual ~Parsowanie();
	vector<Waluta> Parsuj_Plik(std::string nazwa_pliku_do_sparsowania,std::string nazwa_pliku_do_zapisu, std::list<string> lista_walut);
};

#endif /* PARSOWANIE_H_ */
