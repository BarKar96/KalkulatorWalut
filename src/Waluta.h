/*
 * Waluta.h
 *
 *  Created on: May 7, 2016
 *      Author: bartek
 */

#ifndef WALUTA_H_
#define WALUTA_H_

namespace std {

class Waluta
{
private:
	string nazwa_waluty;
	int przelicznik;
	string kod_waluty;
	float kurs_sredni;
public:
	Waluta();
	virtual ~Waluta();
	void wczytaj_walute(std::string nazwa_waluty, int data);
};

} /* namespace std */

#endif /* WALUTA_H_ */
