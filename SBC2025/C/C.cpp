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


void mult(vector<int> &p) {
    for(int i = p.size()-1; i > 0; i--) {
        p[i] = (p[i] + p[i-1]) % 2;
    }

    p[0] = 0;
    p.pb(1);
}

int main() { _

	int N; cin >> N;

    vector<int> p(N+1);

    for (int i = N; i >= 0; i--) {
        int aux; cin >> aux;
        p[i] = aux;
    }

    int res=0;
    while(p.size() != 1) {

        if (p[0]) {
            mult(p);
        } else {
            p.erase(p.begin());
        }

        res++;
    }

    cout << res << endl;

	return 0;
}
