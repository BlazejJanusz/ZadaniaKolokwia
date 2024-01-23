#include <iostream>


using namespace std;

constexpr int MAX_WIERSZE = 50;
constexpr int MAX_KOLUMNY = 50;

int main()
{
    setlocale(LC_ALL, "");
    int x1, y1, x2, y2;
    cout << "Podaj x1, y1, x2, y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    double odleglosc = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Odległość między punktami: " << scientific << odleglosc << endl;

    char tablica[MAX_WIERSZE][MAX_KOLUMNY];
    const char symbole[] = { '*', '&', '$', '#', '@', '!' };
    srand(time(nullptr));

    for (int i = 0; i < x1; ++i) {
        for (int j = 0; j < y1; ++j) {
            tablica[i][j] = symbole[rand() % 6];
        }
    }

    cout << "Zawartość tablicy:" << endl;
    for (int i = 0; i < x1; ++i) {
        for (int j = 0; j < y1; ++j) {
            cout << tablica[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "Widok parzystych wierszy:" << endl;
    for (int i = 0; i < x1; i += 2) {
        for (int j = 0; j < y1; ++j) {
            cout << tablica[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;