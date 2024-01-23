#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	//z1
	short a, b;
	int licznika=0,poprawnaa=0;
	int licznikb=0,poprawnab=0;

	do
	{
		cout << "Podaj liczbę a(ujemna i nieparzysta): "; cin >> a;
		if (a >= 0 || a % 2 == 0)
			licznika++;
		else
			poprawnaa++;
	} while (poprawnaa!=1 && licznika!=3);
	if (licznika == 3)
		a =(-5);
	do
	{
		cout << "Podaj liczbę b(dodatnia i parzysta): "; cin >> b;
		if (b <= 0 || b % 2 != 0)
			licznikb++;
		else
			poprawnab++;
	} while (poprawnab!=1 && licznikb!=3);
	if (licznikb == 3)
		b = 4;
	cout << endl << "a: " << a << endl;
	cout << endl << "b: " << b << endl;
	//z2
	srand(time(NULL));
	const short wiersze = 5;
		const short kolumny = 6;
		short tablica[wiersze][kolumny] = {};
		for(size_t i=0;i<kolumny;i++)
			for (size_t j = 0; j < wiersze; j++)
			{
				tablica[j][i] = (2*a) + rand()%(b-(2*a)+1);
				cout << tablica[j][i]<<",";
			}
		//z3
		const short* wskaznik1 = &tablica[0][0];
		short* wskaznik2=0;
		for(size_t i=0;i<wiersze;i++)
			for (int j = 0; j < kolumny; j++)
			{
				if (tablica[i][j] == b)
					wskaznik2 = &tablica[i][j];
				
			}
		cout << "Odległość od T[0][0]: " << wskaznik2 - wskaznik1 << endl;

}
