#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000; // Ajuste conforme necess�rio
vector<vector<int>> graph(MAXN);
bool visited[MAXN];

// Fun��o para realizar a busca em profundidade (DFS)
void dfs(int node) {
    visited[node] = true;
    for (int v : graph[node]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int count_spots(int n) {
    int spots = 0;
    fill(visited, visited + n + 1, false); // Inicializa o array de visitados

    // Percorre todos os n�s para encontrar componentes conexos
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Cada componente conexo � uma mancha
            dfs(i);
            spots++;
        }
    }

    return spots;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Inicializa o grafo com o n�mero correto de n�s
    graph.assign(n + 1, vector<int>());

    // L� as conex�es
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Conta o n�mero de manchas
    int num_spots = count_spots(n);
    cout << num_spots << endl;

    return 0;
}

