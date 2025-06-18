#include <bits/stdc++.h>
using namespace std;

/*macro para código mais rapido e para \n*/
#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
//^comentar _ para degubar código
#define endl '\n'


/* macro aleatorias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

#define printv(a) do {                             \
    for (size_t i = 0; i < (a).size(); ++i) {      \
        cout << (a)[i];                            \
        if (i < (a).size() - 1)                    \
            cout << " ";                           \
    }                                              \
    cout << endl;                                  \
} while(0)

#define printv2(a) do {                            \
    for (auto x : (a))                             \
        cout << x << endl;                         \
} while(0)

#define print_matrix(m, l, c) do {                 \
    for (int i = 0; i < (l); ++i) {                \
        for (int j = 0; j < (c); ++j) {            \
            cout << (m)[i][j] << " ";              \
        }                                          \
        cout << endl;                              \
    }                                              \
} while(0)


/* macro para trabalhar com pair*/
#define f first
#define s second

/* funcao para debugging*/
#define dgb(x) cout << #x << " = " << x << endl;

/* define long long como ll */
typedef long long ll;


/* define constantes infinitas */
//const int INF = 0x3f3f3f3f;
//const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main() { _

    int x, y;
    cin >> x >> y;

    vector<vector<int>> grid(x, vector<int>(y));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> grid[i][j];

    int minVizinhos = 9;
    set<int> cadeiras;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (grid[i][j] == 0) {
                int vizinhos = 0;
                
                if (i > 0 && grid[i - 1][j - 1] == 1) vizinhos++;
                if (i > 0 && grid[i - 1][j] == 1) vizinhos++;
                if (i > 0 && j < y - 1 && grid[i - 1][j + 1] == 1) vizinhos++;
                if (j > 0 && grid[i][j - 1] == 1) vizinhos++;
                if (j < y - 1 && grid[i][j + 1] == 1) vizinhos++;
                if (i < x - 1 && j > 0 && grid[i + 1][j - 1] == 1) vizinhos++;
                if (i < x - 1 && grid[i + 1][j] == 1) vizinhos++;
                if (i < x - 1 && j < y - 1 && grid[i + 1][j + 1] == 1) vizinhos++;
                
                if (vizinhos < minVizinhos) {
                    minVizinhos = vizinhos;
                    cadeiras.clear();
                    cadeiras.insert((i * y + j) + 1);
                } 
                if (vizinhos == minVizinhos) {
                    cadeiras.insert((i * y + j) + 1);
                }

            }
        }
    }

    cout << minVizinhos << endl;
    for (auto cadeira : cadeiras) {
        cout << cadeira << endl;
    }

    return 0;
}