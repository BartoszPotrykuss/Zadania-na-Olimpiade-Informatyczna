#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> row_parity(n, 0);
    vector<int> column_parity(n, 0);

    for (int i = 0; i < m; i++) {
        int ri, ci;
        cin >> ri >> ci;
        row_parity[ri - 1]++;
        column_parity[ci - 1]++;
    }

    int even_row_parity = 0;
    int odd_row_parity = 0;
    int even_column_parity = 0;
    int odd_column_parity = 0;

    for (int i = 0; i < n; i++) {
        if (row_parity[i] % 2 == 0) {
            even_row_parity++;
        } else {
            odd_row_parity++;
        }

        if (column_parity[i] % 2 == 0) {
            even_column_parity++;
        } else {
            odd_column_parity++;
        }
    }

    if ((even_row_parity == n || odd_row_parity == n) &&
        (even_column_parity == n || odd_column_parity == n)) {
        cout << "TAK" << endl;
        int k = 0;
        for (int i = 0; i < m; i++) {
            if (row_parity[i] % 2 == 1 && column_parity[i] % 2 == 1) {
                k++;
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    } else {
        cout << "NIE" << endl;
    }

    return 0;
}
