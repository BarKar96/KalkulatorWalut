/*
 * Pobieranie.h
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */

#ifndef POBIERANIE_H_
#define POBIERANIE_H_
#include <string>
#include <list>
#include "NazwyPlikowNBP.h"
class Pobieranie
{
public:
	Pobieranie();
	virtual ~Pobieranie();
	long* pobieranie_pliku(std::list<std::string> lista_plikow);
	void pobierz_pliki();
	void pobierz_sciezki();
	void utworz_liste_plikow(std::list<NazwyPlikowNBP>& lista_plikow);
};

#endif /* POBIERANIE_H_ */
