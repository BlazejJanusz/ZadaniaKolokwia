#include <iostream>
#include <cstring>

using namespace std;

using Tekst = char[50];

struct Ksiazka {
	Tekst tytul;
	Tekst autor;
	uint16_t kategoria; //{0 - beletrystyka, 1 - poradnik, 2 - podrecznik, 3 - lektura }
	uint16_t liczbaStron;
};

// https://en.cppreference.com/w/c/string/byte/strcpy
void autorMaksLiczbaStron(Ksiazka* ksiazki, uint16_t n,const char* autor)
{
	uint16_t maksLiczbaStron = 0;
	uint16_t n = sizeof(ksiazki) / sizeof(ksiazki[0]);
	for (uint16_t i = 0; i > n; i++)
	{
		if (ksiazki[n].liczbaStron <  maksLiczbaStron)
		{
			maksLiczbaStron = ksiazki[i].liczbaStron;
			strcpy_s(autor,0, ksiazki[i].autor); 
			kategoria = ksiazki[i].kategoria;

		}
	}
	return kategoria;
}

int main()
{
	setlocale(LC_ALL, "");
	Ksiazka ksiazki[] = {
		{"Operacja Mir","Remigiusz Mróz",0,464},
		{"Atomowe nawyki","James Clear",1,272},
		{"Czysty Kod","Robert Martin",1,424},
		{"Java.Podręcznik na start","Krzysztof Krocz",2,280},
		{"Chłopi","Władysław Reymont",3, 710},
		{"Podręcznik sztuki przetrwania","Raymond Mears",2,240}
	};
	Tekst najlepszyAutor;
	cout << autorMaksLiczbaStron(ksiazki,n,najlepszyAutor) << '\n';
	cout << najlepszyAutor << '\n';
}
