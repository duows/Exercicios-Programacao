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

vector<bool> crivo(int n) {
    vector<bool> primo(n + 1, true);
    primo[0] = primo[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (primo[i]) {
            for (int j = i * i; j <= n; j += i) {
                primo[j] = false;
            }
        }
    }
    return primo;
}

int main() { _

	int x, y; cin >> x >> y;

    vector<bool> eh_primo = crivo(y);

    // Busca o maior primo entre a e b
    for (int i = y; i >= x; --i) {
        if (eh_primo[i]) {
            cout << i << endl;
            return 0;
        }
    }

	return 0;
}