#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 500;
const int MAX_B = 1000;
const int MAX_K = 20;

string RozszerzSlowo(int n, int k, int a, int b, const string& slowo) {
    string S = slowo.substr(0, n); // Pocz¹tkowe s³owo S
    string R = S.substr(S.length() - k); // Pocz¹tkowy sufiks R
    map<char, int> wystapienia; // Liczniki liter

    for (int i = n; i <= b; i++) {
        wystapienia.clear();

        // Zlicz wyst¹pienia liter po sufiksie R
        for (int j = 0; j < n - k; j++) {
            string sufiks = S.substr(j, k);
            if (sufiks == R) {
                char nastepnaLitera = S[j + k];
                wystapienia[nastepnaLitera]++;
            }
        }

        // ZnajdŸ literê, która wyst¹pi³a najczêœciej po sufiksie R
        int maxWystapien = -1;
        char najczestszaLitera = 'a';
        for (const auto& para : wystapienia) {
            if (para.second > maxWystapien) {
                maxWystapien = para.second;
                najczestszaLitera = para.first;
            }
        }

        // Rozszerz S o literê najczestszaLitera i zaktualizuj R
        S += najczestszaLitera;
        R = S.substr(S.length() - k);
    }

    // Wypisz litery od a do b w rozszerzonym s³owie S
    return S.substr(a - 1, b - a + 1);
}

int main() {
    int n, k, a, b;
    string slowo;
    cin >> n >> k >> a >> b >> slowo;

    string wynik = RozszerzSlowo(n, k, a, b, slowo);
    cout << wynik << endl;

    return 0;
}
