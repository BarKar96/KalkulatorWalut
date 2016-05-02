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
void Pobieranie::pobieraniePliku(char *adresURL,const char nazwaPliku[100])
{

	CURL *curl;
	FILE *fp;
	CURLcode res;
	char *url = adresURL;
	char outfilename[100];
	strcpy(outfilename,nazwaPliku);
	curl = curl_easy_init();
	if (curl)
	{
		fp = fopen(outfilename, "w");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
		/* always cleanup */
		curl_easy_cleanup(curl);
		fclose(fp);
	}
}

