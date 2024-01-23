#include <iostream>
#include <ctime>
#include <iomanip>


using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "");
    int wzrost, a, x1, x2, y1, y2;
    double waga, bmi;
    do
    {
        cout << "Podaj swój wzrost: "; cin >> wzrost;
    } while (wzrost <= 0);
    do
    {
        cout << "Podaj swoją wagę: "; cin >> waga;
    } while (waga <= 0);
    bmi = waga / (wzrost * wzrost);
    cout << fixed << setprecision(2) << "Twoje BMI wynosi: " << bmi << endl;
    cout << "Podaj maksymalna wartość tablicy: "; cin >> a;
    const size_t kolumna = 6;
    const size_t wiersze = 5;
    int tablica[wiersze][kolumna] = {};
    cout << endl;
    for (size_t j = 0; j < wiersze; j++)
    {
        int sumaWiersza = 0;
        for (size_t i = 0; i < kolumna; i++)
        {
            tablica[j][i] = rand() % (a);
            cout << tablica[j][i] << ",";
            sumaWiersza += tablica[j][i];
        }
        
        cout << endl << "suma wiersza wynosi: " << sumaWiersza<<endl;
    }
    cout << "Podaj współrzędne punktów: \n";
    cout << "punkt pierwszy(x1,y1) "; cin >> x1 >> y1;
    cout << endl;
    cout << "punkt drugi(x2,y2) "; cin >> x2 >> y2;
    cout << endl;
    int odleglosc = (char*)(&tablica[x1][y1]) - (char*)(&tablica[x2][y2]);
    if (odleglosc < 0)
        odleglosc = odleglosc * (-1);

    cout << odleglosc;
}