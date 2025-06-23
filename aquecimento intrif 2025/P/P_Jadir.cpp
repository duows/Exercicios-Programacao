#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

struct Estrada {
    int to;
    int cor;
    int id;
};

int N, M, K;
vector<vector<Estrada>> adj;
vector<bool> usado;
vector<int> caminho;
vector<int> corAresta;
vector<pair<int, int>> arestas;

void dfs_conexidade(int u, vector<bool>& visitado) {
    visitado[u] = true;
    for (auto& e : adj[u]) {
        if (!visitado[e.to])
            dfs_conexidade(e.to, visitado);
    }
}

bool dfs_ciclo(int u, int corAnterior, int inicio, int primeiraCor, int arestasUsadas) {
    if (arestasUsadas == M) {
        return (u == inicio && primeiraCor != corAnterior);
    }

    for (auto& e : adj[u]) {
        if (!usado[e.id] && e.cor != corAnterior) {
            usado[e.id] = true;
            if (dfs_ciclo(e.to, e.cor, inicio, (arestasUsadas == 0 ? e.cor : primeiraCor), arestasUsadas + 1)) {
                caminho.push_back(e.id);
                return true;
            }
            usado[e.id] = false;
        }
    }

    return false;
}

int main() { _
    cin >> N >> M >> K;

    adj.resize(N + 1);
    usado.resize(M + 1, false);
    corAresta.resize(M + 1);
    arestas.resize(M + 1);

    for (int i = 1; i <= M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c, i});
        adj[v].push_back({u, c, i});
        corAresta[i] = c;
        arestas[i] = {u, v};
    }

    // Verificar graus pares
    for (int u = 1; u <= N; u++) {
        if (adj[u].size() % 2 != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Verificar conexidade
    vector<bool> visitado(N + 1, false);
    int start = -1;
    for (int u = 1; u <= N; u++) {
        if (!adj[u].empty()) {
            start = u;
            break;
        }
    }

    dfs_conexidade(start, visitado);
    for (int u = 1; u <= N; u++) {
        if (!adj[u].empty() && !visitado[u]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Tentar iniciar de cada cidade, começando com cada aresta possível
    for (int u = 1; u <= N; u++) {
        for (auto& e : adj[u]) {
            fill(usado.begin(), usado.end(), false);
            caminho.clear();

            usado[e.id] = true;
            if (dfs_ciclo(e.to, e.cor, u, e.cor, 1)) {
                caminho.push_back(e.id);
                reverse(caminho.begin(), caminho.end());

                cout << u << endl;
                for (int id : caminho)
                    cout << id << " ";
                cout << endl;
                return 0;
            }
            usado[e.id] = false;
        }
    }

    cout << -1 << endl;
    return 0;
}
