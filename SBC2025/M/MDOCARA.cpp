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

/* criar arquivo baseado no template
cp ~/templates/template.cpp ~/projetos/meu_novo_codigo.cpp

compilar
g++ -std=c++17 -o meu_novo_codigo ~/projetos/meu_novo_codigo.cpp
./meu_novo_codigo

criar pastas
for i in {A..Z}; do mkdir -p "$i"; cp ~/templates/template.cpp "$i/$i.cpp"; done
*/

// modelHenrique="/mnt/d/Faculdade/Exercicios-Programacao/modelHenrique.cpp"; for i in {A..J}; do mkdir -p "$i"; cp "$modelHenrique" "$i/$i.cpp"; done

#define MAXN 100100

#define INF 2000000000

int n, k;
int v[MAXN], pref[MAXN], suf[MAXN];

int main() { _

	cin >> n >> k;

    pref[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = min(pref[i - 1], v[i]);
    }

    suf[n + 1] = INF;
    for(int i = n; i > 0 ; i--) {
        suf[i] = min(suf[i + 1], v[i]);
    }

    multiset<int> s;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        s.insert(v[i] + i);

        if (i - k > 0) {
            s.erase(s.find(v[i - k] + i - k));
        }

        int r = *s.begin() - i + k;

        if (i - k > 0) {
            r = min(r, pref[i - k]);
        }

        if (i < n) {
            r = min(r, suf[i + 1]);
        }

        res = max(res, r);
    }

    cout << res << endl;

	return 0;
}
