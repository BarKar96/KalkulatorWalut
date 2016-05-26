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
	long* pobieranie_pliku(std::string koncowka_url);
	void pobierz_sciezki();
	void utworz_liste_plikow(std::list<NazwyPlikowNBP>& lista_plikow);
	void pobierz_dane_z_x_dni(int x, list<NazwyPlikowNBP> lista_plikow);
	void pobierz_dane_z_ostatniego_miesiaca(string miesiac, list<NazwyPlikowNBP> lista_plikow);
	bool sprawdz_czy_plik_jest_sciagniety(NazwyPlikowNBP &obiekt);
};

#endif /* POBIERANIE_H_ */
