#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <queue>

// Estrutura para representar uma estrada na lista de adjacência
struct Edge {
    int to;
    int id;
    int color;
};

// Estrutura para guardar os detalhes de uma estrada para consulta
struct Road {
    int u, v, color;
};

// Variáveis globais para acesso na função recursiva
int N, M, K;
std::vector<std::vector<Edge>> adj;
std::vector<Road> roads;

// Função de busca recursiva (DFS)
void find_tour(int start_node, int current_node, std::vector<int>& path, std::vector<bool>& used_roads) {
    // Caso base: o caminho está completo
    if (path.size() == M) {
        if (current_node == start_node) {
            int first_road_color = roads[path[0]].color;
            int last_road_color = roads[path.back()].color;

            if (first_road_color != last_road_color) {
                // Solução encontrada! Imprime e encerra o programa.
                std::cout << start_node << std::endl;
                for (size_t i = 0; i < path.size(); ++i) {
                    std::cout << path[i] << (i == path.size() - 1 ? "" : " ");
                }
                std::cout << std::endl;
                exit(0);
            }
        }
        return;
    }

    int last_road_color = roads[path.back()].color;

    // Passo recursivo: tenta todas as arestas a partir do nó atual
    for (const auto& edge : adj[current_node]) {
        if (!used_roads[edge.id]) {
            if (edge.color != last_road_color) {
                used_roads[edge.id] = true;
                path.push_back(edge.id);

                find_tour(start_node, edge.to, path, used_roads);

                // Backtrack
                path.pop_back();
                used_roads[edge.id] = false;
            }
        }
    }
}

bool solve() {
    if (!(std::cin >> N >> M >> K)) {
        return false;
    }

    adj.assign(N + 1, std::vector<Edge>());
    roads.assign(M + 1, Road());
    std::vector<int> degree(N + 1, 0);

    for (int i = 1; i <= M; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        roads[i] = {u, v, c};
        adj[u].push_back({v, i, c});
        adj[v].push_back({u, i, c});
        degree[u]++;
        degree[v]++;
    }

    // --- PRÉ-VERIFICAÇÕES ---
    std::vector<int> potential_starts;
    int nodes_with_edges = 0;
    for(int i = 1; i <= N; ++i) {
        if (degree[i] > 0) {
            nodes_with_edges++;
            potential_starts.push_back(i);
        }
    }
    
    if (M > 0 && nodes_with_edges == 0) {
        std::cout << -1 << std::endl;
        return true;
    }
     if (M == 0) {
        std::cout << 1 << std::endl << std::endl;
        return true;
    }

    // 1. Verificação de Conectividade (BFS)
    std::queue<int> q;
    q.push(potential_starts[0]);
    std::vector<bool> visited_component(N + 1, false);
    visited_component[potential_starts[0]] = true;
    int component_size = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(const auto& edge : adj[u]){
            if(!visited_component[edge.to]){
                visited_component[edge.to] = true;
                q.push(edge.to);
                component_size++;
            }
        }
    }
    if(component_size != nodes_with_edges){
        std::cout << -1 << std::endl;
        return true;
    }

    // 2. Verificação de Grau Par
    for (int i = 1; i <= N; ++i) {
        if (degree[i] % 2 != 0) {
            std::cout << -1 << std::endl;
            return true;
        }
    }

    // 3. Verificação de Distribuição de Cores
    for (int i = 1; i <= N; ++i) {
        if (degree[i] > 0) {
            std::map<int, int> color_counts;
            for (const auto& edge : adj[i]) {
                color_counts[edge.color]++;
            }
            for (const auto& pair : color_counts) {
                if (pair.second > degree[i] / 2) {
                    std::cout << -1 << std::endl;
                    return true;
                }
            }
        }
    }

    // --- BUSCA ROBUSTA ---
    for (int start_node : potential_starts) {
        std::vector<bool> used_roads(M + 1, false);
        for (const auto& edge : adj[start_node]) {
            std::vector<int> path;
            path.push_back(edge.id);
            used_roads[edge.id] = true;

            find_tour(start_node, edge.to, path, used_roads);

            used_roads[edge.id] = false; // Backtrack da escolha da primeira aresta
        }
    }

    // Se todos os pontos de partida falharam
    std::cout << -1 << std::endl;
    return true;
}

int main() {
    // Otimização de I/O para C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Loop para múltiplos casos de teste, se houver
    solve();

    return 0;
}