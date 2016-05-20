/*
 * Waluta.h
 *
 *  Created on: May 7, 2016
 *      Author: bartek
 */

#ifndef WALUTA_H_
#define WALUTA_H_
#include <iostream>
#include <string>

namespace std {

class Waluta
{
private:
	std::string nazwa_waluty;
	int przelicznik;
	std::string kod_waluty;
	float kurs_sredni;
public:
	Waluta(std::string nazwa_waluty, int przelicznik, std::string kod_waluty, float kurs_sredni);
	virtual ~Waluta();
	void wczytaj_walute(std::string nazwa_waluty, int data);
	std::string get_nazwa_waluty();
	int get_przelicznik();
	std::string get_kod_waluty();
	float get_kurs_sredni();
	float srednia_wartosc();
};

} /* namespace std */

#endif /* WALUTA_H_ */
