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


int main() { 
    _ 

    int n; 
    int m;
    cin >> n >> m;
    
    double maior_salto_geral = 0.0;
    string nome_campeao;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(int i = 0; i < n; i++) {
        string nome_atual;
        getline(cin, nome_atual);

        for(int j = 0; j < m; j++) {
            string linha_salto;
            getline(cin, linha_salto);

            stringstream ss(linha_salto);
            double salto_atual;
            char char_invalido = 0;

            ss >> salto_atual;
            ss >> char_invalido; 

            if (char_invalido != 'I' && char_invalido != 'T' && salto_atual > maior_salto_geral) {
                maior_salto_geral = salto_atual;
                nome_campeao = nome_atual;
            }
        }
    }


    cout << nome_campeao << endl;
    cout << fixed << setprecision(2) << maior_salto_geral << endl;

    return 0;
}