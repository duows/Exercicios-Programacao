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


int contar_componentes(int n, vector<vector<int>>& adj) {
    vector<bool> visitado(n, false);
    int numero_componentes = 0;


    for (int i = 0; i < n; ++i) {
        if (!visitado[i]) {
            numero_componentes++;

            queue<int> fila;
            fila.push(i);
            visitado[i] = true;

            while (!fila.empty()) {
                int u = fila.front();
                fila.pop();

                for (int v = 0; v < n; ++v) {
                    if (adj[u][v] == 1 && !visitado[v]) {
                        visitado[v] = true;
                        fila.push(v);
                    }
                }
            }
        }
    }
    return numero_componentes;
}


int main() { _

    int n; cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; ++i) {
        int componente_origem;
        cin >> componente_origem;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string linha_conexoes;

        getline(cin, linha_conexoes);
        stringstream ss(linha_conexoes);
        int componente_vizinho;
        while (ss >> componente_vizinho) {
            adj[componente_origem][componente_vizinho] = 1;
            adj[componente_vizinho][componente_origem] = 1;
        }
    }

    int componentes_iniciais = contar_componentes(n, adj);
    
    int enlaces_criticos = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {

            if (adj[i][j] == 1) {
                adj[i][j] = 0;
                adj[j][i] = 0;

                int novos_componentes = contar_componentes(n, adj);

                if (novos_componentes > componentes_iniciais) {
                    enlaces_criticos++;
                }

                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }

    cout << enlaces_criticos << endl;

    return 0;
}