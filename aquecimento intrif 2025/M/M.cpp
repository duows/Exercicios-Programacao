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

	queue<string> normal;
    queue<string> prioritaria;
    
    string s;

    while (cin >> s) {
        if (s == "CHEGADA") {
            string nome;
            int idade;
            cin >> nome >> idade;

            if (idade > 54)
                prioritaria.push(nome);
            else
                normal.push(nome);
        }

        else if (s == "ATENDIMENTO") {
            if (!prioritaria.empty()) {
                cout << prioritaria.front() << endl;
                prioritaria.pop();
            }
            else if (!normal.empty()) {
                cout << normal.front() << endl;
                normal.pop();
            }
            else {
                cout << "FILA VAZIA" << endl;
            }
        }
    }

	return 0;
}