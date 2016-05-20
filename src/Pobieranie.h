/*
 * Pobieranie.h
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */

#ifndef POBIERANIE_H_
#define POBIERANIE_H_
#include <string>
class Pobieranie {
public:
	Pobieranie();
	virtual ~Pobieranie();
	long* pobieranie_pliku(std::string numer_tabel, std::string data, const char nazwa_pliku[100]);
	void pobierz_pliki();
};

#endif /* POBIERANIE_H_ */
