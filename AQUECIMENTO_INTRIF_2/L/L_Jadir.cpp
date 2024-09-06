#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
#define endl '\n'

/* define constantes infinitas
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
*/

int main() { _


    int L, C, N; cin >> L >> C >> N;

    int tabuleiro[L+1][C+1] = {{0}};

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        tabuleiro[x][y] = 1;
    }

    int LP, CP; cin >> LP >> CP;

    tabuleiro[LP][CP] = 2;

    int pontos = 0;
    pair<int, int> pacman = make_pair(LP, CP);

    string movimentos; cin >> movimentos;

    for (char c : movimentos) {

        if (c == 'L') {
            pacman.second++;
        } else if (c == 'O') {
            pacman.second--;
        } else if (c == 'S') {
            pacman.first++;
        } else if (c == 'N') {
            pacman.first--;
        }

        if (pacman.second < 1) {
            pacman.second = 1;
        } else if (pacman.second > C) {
            pacman.second = C;
        } else if (pacman.first < 1) {
            pacman.first = 1;
        } else if (pacman.first > L) {
            pacman.first = L;
        }

        if (tabuleiro[pacman.first][pacman.second] == 0) {
            pontos++;
            tabuleiro[pacman.first][pacman.second] = 2;
        } else if (tabuleiro[pacman.first][pacman.second] == 1) {
            pontos = 0;
        }

    }

    cout << pontos << endl;
    

	return 0;
}
