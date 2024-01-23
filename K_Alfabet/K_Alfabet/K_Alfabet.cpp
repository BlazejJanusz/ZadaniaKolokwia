#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
    int b, a;
    cout << "Podaj liczbe b: "; cin >> b;

    int licznik = 0;
    int lysychuj = 0;
    do
    {
        cout << "Podaj liczby a: "; cin >> a;
        if (a < b - 10 && a > b - 20)
            licznik++;
        else
            lysychuj++;
    } while (licznik != 1 && lysychuj != 3);
    if (licznik != 1)
    {
        b = 30;
        a = 15;
    }
    const size_t rozmiar = 40;

    char tablica[rozmiar] = {};

    srand(time(NULL));
    int litera = 'a';
    for (size_t i = 0; i < rozmiar; i++)
    {
        tablica[i] = rand() % (b - a + 1) + litera;
        cout << tablica[i];
    }
    bool pobieranie = true;
    char szukana;
    char* ostatnia=0;
    do
    {
        cout << "Podaj literę z zakresu tablicy: "; cin >> szukana;
        for (size_t i = 0; i < rozmiar; i++)
        {
            if (szukana == tablica[i])
                ostatnia = &tablica[i];
            pobieranie = false;
        }
    } while (pobieranie == true);
        char* pierwsza=0;
        for (int i = rozmiar - 1; i >=0; i--)
        {
            if (szukana == tablica[i])
                pierwsza = &tablica[i];
        }
        for (size_t i = 0; i < rozmiar; i++)
        {
            if (pierwsza<&tablica[i] && ostatnia>&tablica[i])
                cout << tablica[i];
        }
}