/*
 * Pobieranie.h
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */

#ifndef POBIERANIE_H_
#define POBIERANIE_H_

class Pobieranie {
public:
	Pobieranie();
	virtual ~Pobieranie();
	void pobieranie_pliku(char *adresURL,const char nazwaPliku[100]);

};

#endif /* POBIERANIE_H_ */
