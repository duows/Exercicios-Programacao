
// Algoritmo de Kruskal para encontrar a árvore geradora mínima de um grafo


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
    int u, v, peso;

    bool operator<(const Aresta& other) const {
        return peso < other.peso;
    }
};

struct Grafo {
    int N;
    vector<Aresta> arestas;
    vector<int> parent, rank;

    Grafo(int n) : N(n), parent(n + 1), rank(n + 1, 0) {
        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
        }
    }

    void adicionarAresta(int u, int v, int peso) {
        arestas.push_back({u, v, peso});
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv]) swap(pu, pv);
            parent[pv] = pu;
            if (rank[pu] == rank[pv]) ++rank[pu];
        }
    }

    int kruskal() {
        sort(arestas.begin(), arestas.end());

        int custoTotal = 0;

        for (const auto& aresta : arestas) {
            if (find(aresta.u) != find(aresta.v)) {
                custoTotal += aresta.peso;
                unite(aresta.u, aresta.v);
            }
        }

        return custoTotal;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    Grafo grafo(N);

    for (int i = 0; i < M; ++i) {
        int u, v, peso;
        cin >> u >> v >> peso;
        grafo.adicionarAresta(u, v, peso);
    }

    int custo = grafo.kruskal();

    cout << custo << endl;

    return 0;
}
