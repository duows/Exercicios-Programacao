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

const int INF = 2000000100;

int main() { _

	int n; cin >> n;

    int x, y, lastX, lastY;
    cin >> lastX >> lastY;

    int dist;
    int soma = 0;
    int minV = 0;
    int maxV = INF;
    
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        dist = abs(lastX - x) + abs(lastY - y);
        soma += dist * ((i & 1) ? 1 : -1);

        if (i & 1) {
            maxV = min(maxV, soma);
        } else {
            minV = max(minV, soma);
        }

        lastX = x;
        lastY = y;
    }

    cout << (minV < maxV - 1 ? maxV - 1 : -1) << endl;

	return 0;
}
