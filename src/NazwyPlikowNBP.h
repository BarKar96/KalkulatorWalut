/*
 * NazwyPlikowNBP.h
 *
 *  Created on: May 21, 2016
 *      Author: bartek
 */

#ifndef SRC_NAZWYPLIKOWNBP_H_
#define SRC_NAZWYPLIKOWNBP_H_

#include <iostream>

using namespace std;
class NazwyPlikowNBP {
private:
	string data;
	string przedrostek;

public:
	NazwyPlikowNBP(string data, string przedrostek);
	virtual ~NazwyPlikowNBP();
	string pobierz_nazwe();
	string pobierz_date();
};

#endif /* SRC_NAZWYPLIKOWNBP_H_ */
