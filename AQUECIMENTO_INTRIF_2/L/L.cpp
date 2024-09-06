#include <bits/stdc++.h>

using namespace std;

/* macro para código mais rápido e para \n */
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/* macro aleatórias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

/* macro para trabalhar com pair */
#define f first
#define s second
#define dgb(x) cout << #x << " = " << x << endl;

/* define long long como ll */
typedef long long ll;

/* macro para imprimir matriz */
#define print_matrix(m, l, c) { \
    for (int i = 0; i < l; ++i) { \
        for (int j = 0; j < c; ++j) { \
            cout << m[i][j] << " "; \
        } \
        cout << endl; \
    } \
}

int main() { _

    /*
    0 - ponto
    2 - fantasma
    5 - player
    [0,0][0,1][0,2]
    [1,0][1,1][1,2]
    [2,0][2,1][2,2]
    */

    int l, c; cin >> l >> c;
    
    vector<vector<int>> m(l, vector<int>(c, 1));

    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int aux, aux2; cin >> aux >> aux2;
        m[aux-1][aux2-1] = 2;
    }

    int a, b; cin >> a >> b;
    a--; b--;
    m[a][b] = 5;

    string path; cin >> path;
    
    int linha = a;
    int coluna = b;
    int soma = 0;
    
    for (char& move : path) {
        

        switch (move) {
            case 'N':
                linha--;
                if (linha < 0) {
                	linha = 0;
				}
                break;
            case 'S':
                linha++;
                if (linha > (l - 1)) {
                	linha = (l - 1);
				}
                break;
            case 'L':
                coluna++;
                if (coluna > (c - 1)) {
                	coluna = (c - 1);
				}
                break;
            case 'O':
                coluna--;
                if (coluna < 0) {
                	coluna = 0;
				}
                break;
        }
	
		if (m[linha][coluna] == 2) {
			soma = 0;
		} else {
			if (m[linha][coluna] == 1) {
				soma += 1;
				m[linha][coluna] = 0;
			}
		}
        
    }
    
    cout << soma << endl;

    return 0;
}

