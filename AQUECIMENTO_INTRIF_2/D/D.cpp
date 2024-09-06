#include <bits/stdc++.h>

using namespace std;

/*macro para código mais rápido e para \n*/
#define _ ios_base::sync_with_stdio(0); cin.tie(0); //não usar printf junto com cout
//^comentar _ para debugar código
#define endl '\n'

/* macro aleatórias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define mp make_pair
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

/* função para debugging*/
#define dgb(x) cout << #x << " = " << x << endl;

/* define long long como ll */
typedef long long ll;

double distancia(int x, int y, int x1, int y1) {
    return abs(x - x1) + abs(y - y1);
}

/* define constantes infinitas */
//const int INF = 0x3f3f3f3f;
//const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    ll dx, dy, n, q; 
    int caso = 1;

    while (dx || dy || n || q) {
    	cin >> dx >> dy >> n >> q;
    	if (dx == 0 && dy == 0 && n == 0 && q == 0) {
    		break;
		}
        vector<pii> coord(n);
        vector<int> consultas(q);
        
        for (int i = 0; i < n; ++i) {
            cin >> coord[i].f >> coord[i].s;
        }

        for (int i = 0; i < q; ++i) {
            cin >> consultas[i];
        }

        cout << "Caso " << caso++ << ":" << endl;

        for (int m : consultas) {
            int max_count = 0;
            pii melhor_local = {dx, dy};

            for (int x = 1; x <= dx; ++x) {
                for (int y = 1; y <= dy; ++y) {
                    int count = 0;
        
                    for (const auto& r : coord) {
                        if (distancia(x,y,r.f,r.s) <= m) {
                            ++count;
                        }
                    }
                    
                    if (count > max_count ||
                        (count == max_count && (y < melhor_local.s ||
                        (y == melhor_local.s && x < melhor_local.f)))) {
                        max_count = count;
                        melhor_local = {x, y};
                    }
                }
            }
            
            cout << max_count << " (" << melhor_local.f << "," << melhor_local.s << ")" << endl;
        }
    }

    return 0;
}

