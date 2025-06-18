#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main() { _
    int L, C;
    cin >> L >> C;

    vector<vector<char>> board(L, vector<char>(C, '*'));

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int lf, cf;
        cin >> lf >> cf;
        board[lf - 1][cf - 1] = 'F'; // ajusta para índice 0
    }

    // Posição inicial do Pacman
    int lp, cp; cin >> lp >> cp;
    lp--; cp--;

    board[lp][cp] = ' ';

    string moves;
    cin >> moves;

    int score = 0;

    for (char move : moves) {
        int new_lp = lp, new_cp = cp;

        if (move == 'N') new_lp--;
        else if (move == 'S') new_lp++;
        else if (move == 'L') new_cp++;
        else if (move == 'O') new_cp--;

        if (new_lp < 0 || new_lp >= L || new_cp < 0 || new_cp >= C)
            continue;

        lp = new_lp;
        cp = new_cp;

        if (board[lp][cp] == 'F') {
            score = 0;
        } else if (board[lp][cp] == '*') {
            score++;
            board[lp][cp] = ' ';
        }
    }

    cout << score << endl;

    return 0;
}
