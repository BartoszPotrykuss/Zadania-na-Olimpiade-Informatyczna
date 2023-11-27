#include <iostream>
#include <vector>
using namespace std;

int main() {
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

    // Zliczanie kropek w rzędach
    for (int i = 0; i < n; i++) {
        int licznik = 0;
        for (int j = 0; j < n; j++) {
            if (lotnisko[i][j] == '.') {
                licznik++;
            } else {
                licznik = 0; // Resetuj licznik, jeśli nie ma kropki
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
                licznik = 0; // Resetuj licznik, jeśli nie ma kropki
            }
            kropkiPionowo[j] = max(kropkiPionowo[j], licznik);
        }
    }

         // Znajdowanie maksymalnej długości pasów startowych
    int maxRunwayLength = 0;
    for (int i = 0; i < n; i++) {
        maxRunwayLength = max(maxRunwayLength, kropkiPoziomo[i]);
        maxRunwayLength = max(maxRunwayLength, kropkiPionowo[i]);
    }

    // Ograniczanie długości pasów przez podaną liczbę
    maxRunwayLength = min(maxRunwayLength, numRunways);

    cout << maxRunwayLength << endl;
    /*
    int n, m;
    cin >> n >> m;
    vector<vector<char>> airport(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> airport[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Inicjalizacja wartoœci na pierwszym wierszu i kolumnie
    for (int i = 0; i < n; i++) {
        dp[i][0] = (airport[i][0] == '.') ? 1 : 0;
        dp[0][i] = (airport[0][i] == '.') ? 1 : 0;
    }

    int maxLen = 0;  // Maksymalna d³ugoœæ pasów startowych

    // Obliczanie dp
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (airport[i][j] == '.') {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    if (m == 1) {
        cout << maxLen << endl;
    } else {
        // Sprawdzamy, czy mo¿na zbudowaæ dwa pasy startowe
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (airport[i][j] == '.') {
                    // Rozwa¿amy pasy startowe zaczynaj¹ce siê w punkcie (i, j)
                    for (int k = 1; k < maxLen; k++) {
                        if (i + k < n && j + k < n && dp[i+k][j+k] >= k) {
                            cout << k << endl;
                            return 0;
                        }
                    }
                }
            }
        }
        cout << 0 << endl;  // Jeœli nie mo¿na zbudowaæ dwóch pasów startowych
    }
    */
    return 0;
}
