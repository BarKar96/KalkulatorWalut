/*
 * Pobieranie.cpp
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */

#include "Pobieranie.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
Pobieranie::Pobieranie()
{
	// TODO Auto-generated constructor stub

}

Pobieranie::~Pobieranie()
{
	// TODO Auto-generated destructor stub
}
long* Pobieranie::pobieranie_pliku(string numer_tabeli,string data,const char nazwaPliku[100])
{

	CURL *curl;
	FILE *fp;
	CURLcode res;
	string url="http://www.nbp.pl/kursy/xml/a";
	url+=numer_tabeli;
	url+="z";
	url+=data;
	url+=".xml";
	//cout << url;
	char outfilename[100];
	strcpy(outfilename,nazwaPliku);
	curl = curl_easy_init();
	long *responce;
	if (curl)
	{

		fp = fopen(outfilename, "w");
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
		responce = new long;
		curl_easy_getinfo(curl,CURLINFO_RESPONSE_CODE, responce);
		//cout<<*responce<<endl;

		/* always cleanup */
		curl_easy_cleanup(curl);
		fclose(fp);
	}

	return responce;

}
void Pobieranie::pobierz_pliki()
{
	string numer_tabelki="005";
	int numer_tabeli;
	numer_tabeli=atof(numer_tabelki.c_str());

	cout << "numer tabeli:"<<numer_tabeli<<endl;
	ostringstream ss;
//	ss<<numer_tabeli;
//	cout << ss.str();
	string data="160111";
	long *responce;
	int i=0;
	//while (i!=30)
	//{
		responce=pobieranie_pliku(numer_tabelki,data,"plik.txt");
		//cout <<*responce;
		if ((*responce)==200)
		{
			if(numer_tabeli<10)
			{
				numer_tabeli++;
				ss<<numer_tabeli;
				numer_tabelki="00"+ss.str();
				cout << numer_tabelki;
			}
			if(numer_tabeli>9 && numer_tabeli<100)
			{
			numer_tabeli++;
			ss << numer_tabeli;
			numer_tabelki = "0" + ss.str();
			cout << numer_tabelki;
			}
			i++;
			//cout<<i;
		}
		//else

	//}
}
