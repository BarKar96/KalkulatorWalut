//============================================================================
// Name        : KalkulatorWalut.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <curl/curl.h>
#include "Pobieranie.h"
#include "Parsowanie.h"
using namespace std;

int main()
{
	Parsowanie w;
	w.Parsuj_Plik("plik.txt","parsowanie.txt");
	cout << "!!!Hello World!!!!";
	return 0;
}
