/*
 * UI.h
 *
 *  Created on: May 24, 2016
 *      Author: bartek
 */

#ifndef SRC_UI_H_
#define SRC_UI_H_
#include "Waluta.h"
#include "NazwyPlikowNBP.h"
#include <vector>
#include <list>
#include <string>
using namespace std;
class UI
{
public:
	UI();
	virtual ~UI();
	void pokaz_aktualne_kursy(list<vector<Waluta> > lista_wektorow);
	void dodaj_walute_do_listy(list<string>& lista_walut, string kod);
	void pokaz_waluty_z_dnia(list<vector<Waluta> > lista_wektorow, list<NazwyPlikowNBP> lista_plikow, string data);
	void pokaz_rokowania_na_podstawie_x_dni();
};

#endif /* SRC_UI_H_ */
