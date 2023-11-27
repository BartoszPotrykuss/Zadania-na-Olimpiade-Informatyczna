#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, numRunways;
    cin >> n >> numRunways;
    vector<vector<char>> lotnisko(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lotnisko[i][j];
        }
    }

    vector<int> kropkiPoziomo(n, 0);
    vector<int> kropkiPionowo(n, 0);

    // Zliczanie kropek w rzêdach
    for (int i = 0; i < n; i++) {
        int licznik = 0;
        for (int j = 0; j < n; j++) {
            if (lotnisko[i][j] == '.') {
                licznik++;
            } else {
                licznik = 0; // Resetuj licznik, jeœli nie ma kropki
            }
            kropkiPoziomo[i] = max(kropkiPoziomo[i], licznik);
        }
    }

    // Zliczanie kropek w kolumnach
    for (int j = 0; j < n; j++) {
        int licznik = 0;
        for (int i = 0; i < n; i++) {
            if (lotnisko[i][j] == '.') {
                licznik++;
            } else {
                licznik = 0; // Resetuj licznik, jeœli nie ma kropki
            }
            kropkiPionowo[j] = max(kropkiPionowo[j], licznik);
        }
    }

    // Wyœwietlanie wyników
    cout << "Poziomo:" << endl;
    for (int i = 0; i < n; i++) {
        cout << kropkiPoziomo[i] << endl;
    }

    cout << "Pionowo:" << endl;
    for (int i = 0; i < n; i++) {
        cout << kropkiPionowo[i] << endl;
    }


     // Znajdowanie maksymalnej d³ugoœci pasów startowych
    int maxRunwayLength = 0;
    for (int i = 0; i < n; i++) {
        maxRunwayLength = max(maxRunwayLength, kropkiPoziomo[i]);
        maxRunwayLength = max(maxRunwayLength, kropkiPionowo[i]);
    }

    // Ograniczanie d³ugoœci pasów przez podan¹ liczbê
    maxRunwayLength = min(maxRunwayLength, numRunways);

    cout << "Maksymalna dlugosc pasow startowych: " << maxRunwayLength << endl;
    return 0;
}
