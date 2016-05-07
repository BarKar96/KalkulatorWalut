/*
 * Parsowanie.h
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */

#ifndef PARSOWANIE_H_
#define PARSOWANIE_H_
#include <iostream>
#include <cstring>
using namespace std;
class Parsowanie
{
public:
	Parsowanie();
	virtual ~Parsowanie();
	void Parsuj_Plik(std::string nazwa_pliku_do_sparsowania,std::string nazwa_pliku_do_zapisu);
};

#endif /* PARSOWANIE_H_ */
