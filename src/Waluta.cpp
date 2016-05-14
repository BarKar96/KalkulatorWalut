/*
 * Waluta.cpp
 *
 *  Created on: May 7, 2016
 *      Author: bartek
 */

#include "Waluta.h"
#include <iostream>
using namespace std;


Waluta::Waluta(std::string nazwa_waluty, int przelicznik, std::string kod_waluty, float kurs_sredni)
{
	this->nazwa_waluty=nazwa_waluty;
	this->przelicznik=przelicznik;
	this->kod_waluty=kod_waluty;
	this->kurs_sredni=kurs_sredni;

}

Waluta::~Waluta() {
	// TODO Auto-generated destructor stub
}


void Waluta::wczytaj_walute(string nazwa_waluty, int data)
{

}
string Waluta::get_nazwa_waluty()
{
	return nazwa_waluty;
}
int Waluta::get_przelicznik()
{
	return przelicznik;
}
string Waluta::get_kod_waluty()
{
	return kod_waluty;
}
float Waluta::get_kurs_sredni()
{
	return kurs_sredni;
}
