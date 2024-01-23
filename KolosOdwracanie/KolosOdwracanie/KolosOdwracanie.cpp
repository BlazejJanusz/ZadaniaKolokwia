#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "");
    int n = 0;
    int ink = 0;
    int proby = 0;
    int liczba;
    bool pobieranie = true;
    do
    {
        cout << "Podaj liczbe naturalna n nie wieksza niz 15" << endl;
        cin >> n;

    } while (n > 15 || n < 0);
    const size_t Rozmiar = 20;
    int tab[Rozmiar] = { 0 };

    for (size_t i = 0; i < n; i++)
    {
        cout << "Podaj liczbę: "; cin >> liczba;

        if (liczba <= 0 || liczba >= 100 || liczba % 2 != 0)
            proby++;

        else
        {
            tab[i] = liczba;
            ink++;
        }
        cout << endl << "ilosc prob" << proby << endl;

        if (n == ink)
            break;
        if (proby == 2)
            break;

    }
    for (int i = 0; i < Rozmiar; i++)
        cout << tab[i] << ",";

    cout << endl;
    for (size_t i = 0; i < Rozmiar; i++)
    {
        if (tab[i] == 0)
            tab[i] = 10 + rand() % (100 - 10);
        while (tab[i] % 2 == 1)
            tab[i] = 10 + rand() % (100 - 10);
    }
    for (size_t i = 0; i < Rozmiar; i++)
        cout << tab[i] << ",";

    int* wskaznik1, * wskaznik2;
    int srodek = Rozmiar / 2.0;
    for (size_t i = 0; i < srodek; i++)
    {
        wskaznik1 = &tab[i];
        wskaznik2 = &tab[Rozmiar - 1 - i];
        swap(*wskaznik1, *wskaznik2);
    }
    cout << endl;
    for (int i = 0; i < Rozmiar; i++)
        cout << tab[i] << ",";
}