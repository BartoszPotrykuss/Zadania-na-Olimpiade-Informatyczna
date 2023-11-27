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

    // Zliczanie kropek w rz�dach
    for (int i = 0; i < n; i++) {
        int licznik = 0;
        for (int j = 0; j < n; j++) {
            if (lotnisko[i][j] == '.') {
                licznik++;
            } else {
                licznik = 0; // Resetuj licznik, je�li nie ma kropki
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
                licznik = 0; // Resetuj licznik, je�li nie ma kropki
            }
            kropkiPionowo[j] = max(kropkiPionowo[j], licznik);
        }
    }

    // Wy�wietlanie wynik�w
    cout << "Poziomo:" << endl;
    for (int i = 0; i < n; i++) {
        cout << kropkiPoziomo[i] << endl;
    }

    cout << "Pionowo:" << endl;
    for (int i = 0; i < n; i++) {
        cout << kropkiPionowo[i] << endl;
    }


     // Znajdowanie maksymalnej d�ugo�ci pas�w startowych
    int maxRunwayLength = 0;
    for (int i = 0; i < n; i++) {
        maxRunwayLength = max(maxRunwayLength, kropkiPoziomo[i]);
        maxRunwayLength = max(maxRunwayLength, kropkiPionowo[i]);
    }

    // Ograniczanie d�ugo�ci pas�w przez podan� liczb�
    maxRunwayLength = min(maxRunwayLength, numRunways);

    cout << "Maksymalna dlugosc pasow startowych: " << maxRunwayLength << endl;
    return 0;
}
