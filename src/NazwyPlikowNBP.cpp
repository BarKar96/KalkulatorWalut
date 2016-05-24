/*
 * NazwyPlikowNBP.cpp
 *
 *  Created on: May 21, 2016
 *      Author: bartek
 */

#include "NazwyPlikowNBP.h"

NazwyPlikowNBP::NazwyPlikowNBP(string przedrostek, string data): data(data), przedrostek(przedrostek)
{
}

std::string NazwyPlikowNBP::pobierz_nazwe()
{
	return przedrostek.append(data);
}

NazwyPlikowNBP::~NazwyPlikowNBP() {
}

std::string NazwyPlikowNBP::pobierz_date()
{
	return this->data;
}
//ok oddaje kontrole
//czyli jaki mam nastepny kro
