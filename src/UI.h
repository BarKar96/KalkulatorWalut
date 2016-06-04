/*
 * UI.h
 *
 *  Created on: May 24, 2016
 *      Author: bartek
 */

#ifndef SRC_UI_H_
#define SRC_UI_H_
#include "Waluta.h"
#include "DataIWaluty.h"
#include "NazwyPlikowNBP.h"
#include <vector>
#include <list>
#include <string>

class UI
{
public:
	UI();
	virtual ~UI();
	void pokaz_aktualne_kursy(std::list<DataIWaluty> kursy_walut);
	void dodaj_walute_do_listy(list<string>& lista_walut, string kod);
	void pokaz_waluty_z_dnia(std::list<DataIWaluty> kursy_walut, std::string data);
	void pokaz_rokowania_na_podstawie_x_dni();
	void pokaz_kursy_z_x_dni(list<DataIWaluty> kursy_walut,list<string> lista_walut, int wiersze);
	void wyswietl_kursy_z_x_dni(list<NazwyPlikowNBP>& lista_plikow, int x,list<DataIWaluty>& kursy_walut, vector<Waluta>& tablica_walut,list<string>& lista_walut);
	void wyswietl_kursy_walut_z_dnia(list<NazwyPlikowNBP>& lista_plikow, int x,list<DataIWaluty>& kursy_walut, vector<Waluta>& tablica_walut,list<string>& lista_walut,string data);
};

#endif /* SRC_UI_H_ */
