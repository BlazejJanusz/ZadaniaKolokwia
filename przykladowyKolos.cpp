#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> alokuj_tablice(int wiersze, int kolumny) {
    // Alokacja pamięci dla tablicy 2D + 1 na przechowywanie rozmiarów
    vector<vector<int>> tablica(wiersze, vector<int>(kolumny));

    // Zapisanie rozmiarów do elementu [-1][0]
    tablica.insert(tablica.begin(), { wiersze, kolumny });

    return tablica;
}

int main() {
    int wiersze = 5;
    int kolumny = 3;

    auto tablica = alokuj_tablice(wiersze, kolumny);

    // Wyświetlenie rozmiarów
    cout << "Liczba wierszy: " << tablica[0][0] << endl;
    cout << "Liczba kolumn: " << tablica[0][1] << endl;

    // Użycie tablicy - przykład
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            tablica[i + 1][j] = i * kolumny + j;
            cout << tablica[i + 1][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


void zapisz_do_pliku(const vector<vector<int>>& tablica, const string& nazwa_pliku) {
    ofstream plik(nazwa_pliku, ios::binary);
    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku do zapisu." << endl;
        return;
    }

    // Zapisanie liczby wierszy i kolumn do pliku
    int wiersze = tablica.size();
    int kolumny = tablica[0].size();
    plik.write(reinterpret_cast<const char*>(&wiersze), sizeof(int));
    plik.write(reinterpret_cast<const char*>(&kolumny), sizeof(int));

    // Zapisanie danych tablicy do pliku
    for (const auto& wiersz : tablica) {
        for (int element : wiersz) {
            plik.write(reinterpret_cast<const char*>(&element), sizeof(int));
        }
    }

    plik.close();
}

int main() {
    // Przykładowa tablica
    vector<vector<int>> tablica = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    // Zapis do pliku binarnego
    zapisz_do_pliku(tablica, "tablica.bin");

    return 0;
}
vector<vector<int>> odczytaj_z_pliku(const string& nazwa_pliku) {
    vector<vector<int>> tablica;

    ifstream plik(nazwa_pliku, ios::binary);
    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku do odczytu." << endl;
        return tablica;
    }

    // Odczytanie liczby wierszy i kolumn z pliku
    int wiersze, kolumny;
    plik.read(reinterpret_cast<char*>(&wiersze), sizeof(int));
    plik.read(reinterpret_cast<char*>(&kolumny), sizeof(int));

    // Utworzenie tablicy o odpowiednich rozmiarach
    tablica.resize(wiersze, vector<int>(kolumny));

    // Odczytanie danych tablicy z pliku
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            plik.read(reinterpret_cast<char*>(&tablica[i][j]), sizeof(int));
        }
    }

    plik.close();
    return tablica;
}

int main() {
    // Odczyt z pliku binarnego
    vector<vector<int>> odczytana_tablica = odczytaj_z_pliku("tablica.bin");

    // Wyświetlenie odczytanej tablicy
    for (const auto& wiersz : odczytana_tablica) {
        for (int element : wiersz) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
