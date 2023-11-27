#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, p, M;
    cin >> n >> p >> M;

    vector<pair<int, int>> connections(p);
    for (int i = 0; i < p; i++) {
        cin >> connections[i].first >> connections[i].second;
    }

    int code_length = 1; // Pocz¹tkowa d³ugoœæ kodów to 1.
    while (1 << code_length < n) {
        code_length++;
    }

    cout << code_length << endl;

    vector<string> codes(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        codes[i] = string(code_length, 'A'); // Pocz¹tkowo wszystkie kody to 'A'.
    }

    set<string> used_codes; // Zbiór u¿ytych kodów.

    for (int i = 0; i < p; i++) {
        int sat1 = connections[i].first;
        int sat2 = connections[i].second;

        // Generowanie nowych kody w taki sposób, ¿eby mia³y co najmniej jedn¹ wspóln¹ literê.
        for (int j = 0; j < code_length; j++) {
            if (codes[sat1 - 1][j] == codes[sat2 - 1][j]) {
                // Wybieramy literê, która jest ró¿na od wspólnego znaku.
                for (char c = 'A'; c <= 'C'; c++) {
                    if (c != codes[sat1 - 1][j]) {
                        codes[sat1 - 1][j] = codes[sat2 - 1][j] = c;
                        break;
                    }
                }
                break;
            }
        }
        used_codes.insert(codes[sat1 - 1]);
        used_codes.insert(codes[sat2 - 1]);
    }

    for (int i = 0; i < 2 * n; i++) {
        if (used_codes.find(codes[i]) != used_codes.end()) {
            // Jeœli kod jest ju¿ u¿ywany, zmieniamy go na inny.
            for (char c = 'A'; c <= 'C'; c++) {
                if (used_codes.find(codes[i] + c) == used_codes.end()) {
                    codes[i] += c;
                    used_codes.insert(codes[i]);
                    break;
                }
            }
        } else {
            used_codes.insert(codes[i]);
        }

        cout << codes[i] << endl;
    }

    return 0;
}
