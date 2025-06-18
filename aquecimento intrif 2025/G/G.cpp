#include <bits/stdc++.h>
using namespace std;

// Macros úteis
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main() { _
    string s;
    cin >> s;

    vector<vector<char>> chess(8, vector<char>(8, '.'));

    int row = 0, col = 0;

    for (char c : s) {
        if (c == '/') {
            row++;
            col = 0;
            continue;
        }

        if (isdigit(c)) {
            int num = c - '0';
            col += num;
        } else {
            chess[row][col] = c;
            col++;
        }
    }

    // Imprime o tabuleiro
    for (int i = 0; i < 8; ++i) {
        cout << '|';
        for (int j = 0; j < 8; ++j) {
            if (chess[i][j] == '.')
                cout << ' ';
            else { cout << chess[i][j]; }

            if (j < 7) cout << '|';
        }
        cout << '|' << endl;
    }

    return 0;
}