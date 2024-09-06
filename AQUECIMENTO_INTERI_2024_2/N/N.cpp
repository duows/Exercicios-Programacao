#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); // não usar printf junto com cout
#define endl '\n'

class Graph {
    int V;
    unordered_map<int, set<int>> l;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, bool bidir=true) {
        l[u].insert(v);
        if (bidir) {
            l[v].insert(u);
        }
    }

    int bfs(int source, int destination) {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> dist;

        visited[source] = true;
        q.push(source);
        dist[source] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination) {
                return dist[node];
            }

            for (auto neighbour : l[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    dist[neighbour] = dist[node] + 1;
                }
            }
        }

        return -1; // Caso não encontre o destino (embora o problema garanta que sempre existe)
    }
};

int main() { _

    int r, c; 
    cin >> r >> c;

    unordered_map<char, set<int>> mapa;

    Graph g(r * c);
    char teclado[r][c];

    // Lendo a matriz de teclas
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> teclado[i][j];
            mapa[teclado[i][j]].insert(i * c + j);  // Mapeando a tecla para sua posição linear
        }
    }

    // Construindo o grafo
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int u = i * c + j;  // Convertendo (i, j) para índice linear
            if (i - 1 >= 0) {
                int v = (i - 1) * c + j;
                g.addEdge(u, v);
            }

            if (i + 1 < r) {
                int v = (i + 1) * c + j;
                g.addEdge(u, v);
            }

            if (j - 1 >= 0) {
                int v = i * c + (j - 1);
                g.addEdge(u, v);
            }

            if (j + 1 < c) {
                int v = i * c + (j + 1);
                g.addEdge(u, v);
            }
        }
    }

    string palavra; 
    cin >> palavra;

    int source = 0;  // Começa da posição (0, 0)
    int dist = 0;

    // Percorrendo a palavra e calculando a distância
    for (char c : palavra) {
        const set<int>& positions = mapa[c];
        int minDist = INT_MAX;
        int nearestPosition = -1;

        for (int pos : positions) {
            int d = g.bfs(source, pos);
            if (d < minDist) {
                minDist = d;
                nearestPosition = pos;
            }
        }
        dist += minDist;
        source = nearestPosition;
    }

    // Busca a tecla "Enter" ('*')
    int enter = *mapa['*'].begin();
    int d = g.bfs(source, enter);
    dist += d;

    cout << dist << endl;
    return 0;
}
