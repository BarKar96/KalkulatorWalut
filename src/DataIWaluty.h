/*
 * DataIWaluty.h
 *
 *  Created on: Jun 3, 2016
 *      Author: bartek
 */

#ifndef SRC_DATAIWALUTY_H_
#define SRC_DATAIWALUTY_H_


#include "Waluta.h"
#include <iostream>




#include <vector>

#include <string>


using namespace std;
class DataIWaluty {
public:
	string data;
	vector<Waluta> wektor_walut;
	DataIWaluty();
	virtual ~DataIWaluty();
};

#endif /* SRC_DATAIWALUTY_H_ */
