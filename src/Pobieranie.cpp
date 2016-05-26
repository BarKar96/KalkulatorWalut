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
long* Pobieranie::pobieranie_pliku(string koncowka_url)
{
	CURL *curl;
	FILE *fp;
	CURLcode res;
	string url="http://www.nbp.pl/kursy/xml/.xml";
	char outfilename[100];
	string nazwa_pliku=koncowka_url;

	url.insert(28,koncowka_url);

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
template <class ReverseIterator>
typename ReverseIterator::iterator_type make_forward(ReverseIterator rit)
{
    return --(rit.base());
}
void Pobieranie::pobierz_dane_z_x_dni(int x,list<NazwyPlikowNBP> lista_plikow)
{

	Pobieranie temp;
	int i=0;

	for(list<NazwyPlikowNBP>::reverse_iterator it=lista_plikow.rbegin(); it!=lista_plikow.rend(); ++it)
	{
		NazwyPlikowNBP wsk = *it;
		if(i == x)
			break;
		if(sprawdz_czy_plik_jest_sciagniety(wsk)==0)
		{
			temp.pobieranie_pliku(wsk.pobierz_nazwe());
			cout<<"Pobieram plik"<<endl;
		}
		else
		{
			cout<<"plik z danego dnia istnieje"<<endl;;

		}
		i++;
	}
}
void Pobieranie::pobierz_dane_z_ostatniego_miesiaca(string miesiac, list<NazwyPlikowNBP> lista_plikow)
{
	Pobieranie temp;
	string sprawdz_miesiac;


	for(list<NazwyPlikowNBP>::iterator it = lista_plikow.begin();it!=lista_plikow.end(); it++)
	{
		sprawdz_miesiac=(*it).pobierz_date().substr(2,2);
		if(!strcmp(sprawdz_miesiac.c_str(),miesiac.c_str()) && sprawdz_czy_plik_jest_sciagniety(*it)==0)
		{
			temp.pobieranie_pliku((*it).pobierz_nazwe());

		}
		it++;

	}
}
bool Pobieranie::sprawdz_czy_plik_jest_sciagniety(NazwyPlikowNBP &obiekt)
{
	fstream plik;
	obiekt.pobierz_nazwe();
	plik.open((obiekt).pobierz_nazwe().c_str(),ios::in);
	if(plik.good())
	{

		return 1;
	}
	else
	{
		return 0;
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



