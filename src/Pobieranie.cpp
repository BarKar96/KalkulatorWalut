/*
 * Pobieranie.cpp
 *
 *  Created on: May 1, 2016
 *      Author: bartek
 */
#include "NazwyPlikowNBP.h"
#include "Pobieranie.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <curl/curl.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <list>

using namespace std;
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

Pobieranie::Pobieranie()
{

}

Pobieranie::~Pobieranie()
{
	// TODO Auto-generated destructor stub
}
long* Pobieranie::pobieranie_pliku(list<string> lista_plikow)
{

	CURL *curl;
	FILE *fp;
	CURLcode res;

	string url="http://www.nbp.pl/kursy/xml/.xml";



	char outfilename[100];

	string nazwa_pliku="plik.txt";
	ostringstream ss;
	//ss<<numer_pliku;
	string str;
	str=ss.str();
	nazwa_pliku.insert(4,str);


	strcpy(outfilename,nazwa_pliku.c_str());

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
void Pobieranie::pobierz_sciezki()
{
	CURLcode res;
		CURL *curl;
		FILE *fp;
		char outfilename[100];
		strcpy(outfilename, "kursy.txt");
		string url="http://www.nbp.pl/kursy/xml/dir.txt";
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
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, responce);
			//cout<<*responce<<endl;

			/* always cleanup */
			curl_easy_cleanup(curl);
			fclose(fp);
		}
}

void Pobieranie::utworz_liste_plikow(list<NazwyPlikowNBP>& lista_plikow)
{
	ifstream plik;
	plik.open("sparsowane_kursy.txt");
	string wyraz;
	while(plik.good())
	{
		wyraz.clear();
		plik>>wyraz;
		if (wyraz.length()<11)
		{
			cout<<"blad podczas pobierania nazw plikow";
			return;
		}
		lista_plikow.push_back(NazwyPlikowNBP(wyraz.substr(0,5), wyraz.substr(5,6)));


	}
	plik.close();
}

//Nastepny krok
//1 funkcja ktora pobiera dane z ostanich x dni
//2 funkcja ktora pobiera dane z danego miesiaca z roku to juz bylaby przeginka

//3 usprawnic funkcje tak zeby na poczatku sprawdzila czy juz czasem tych danych nie sciagnela na dysk
//w przypadku jak sciagnela to wczytac te z dysku jak nie to sciagnac

//4 zrobic prosta klase UI w ktorej w whilu dasz uzytkownikowi wybrac co masz przedstawic
// pomysl jakie opcje poki co mozesz mu wyswietlic
//5 zrob funkcje srednia dajaca srednia np dla danego miesiaca

//ok,



