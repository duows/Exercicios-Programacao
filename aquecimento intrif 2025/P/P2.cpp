#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

// Structure to hold information about each road (edge).
struct Edge {
    int to;    // The city this edge connects to.
    int color; // The color of this edge.
    int id;    // The unique ID of this road (1 to M).
};

// Global variables for graph representation and properties.
vector<vector<Edge>> adj;           // Adjacency list for the graph.
vector<int> degree;                 // Stores the degree of each city.
vector<bool> visited_nodes_dfs;     // Used for the connectivity check.
int nodes_with_edges_count = 0;     // Counts nodes with at least one road.

/**
 * Performs a Depth First Search (DFS) to check graph connectivity.
 * It traverses the graph starting from node u and decrements a global counter
 * for each unique node with edges it visits.
 * u: The current city (node) to visit.
 */
void check_connectivity_dfs(int u) {
    visited_nodes_dfs[u] = true;
    nodes_with_edges_count--;
    for (const auto& edge : adj[u]) {
        if (!visited_nodes_dfs[edge.to]) {
            check_connectivity_dfs(edge.to);
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K; // N: cities, M: roads, K: colors
    cin >> N >> M >> K;

    // Initialize data structures
    adj.resize(N + 1);
    degree.assign(N + 1, 0);

    // Read road data and build the graph
    for (int i = 1; i <= M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        // The graph is undirected, so add edges for both directions
        adj[u].push_back({v, c, i});
        adj[v].push_back({u, c, i});
        degree[u]++;
        degree[v]++;
    }

    // --- Pre-checks for Tour Existence ---

    // 1. Connectivity Check: All roads must be in one component.
    int start_node_for_dfs = -1;
    for (int i = 1; i <= N; ++i) {
        if (degree[i] > 0) {
            nodes_with_edges_count++;
            if (start_node_for_dfs == -1) {
                start_node_for_dfs = i;
            }
        }
    }
    if (start_node_for_dfs != -1) {
        visited_nodes_dfs.assign(N + 1, false);
        check_connectivity_dfs(start_node_for_dfs);
        if (nodes_with_edges_count != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    // 2. Even Degree Check: In an Eulerian circuit, every vertex must have an even degree.
    for (int i = 1; i <= N; ++i) {
        if (degree[i] % 2 != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    // 3. Color Diversity Check: At any city, roads of one color can't be more than half the total.
    for (int i = 1; i <= N; ++i) {
        if (degree[i] > 0) {
            map<int, int> color_counts;
            for (const auto& edge : adj[i]) {
                color_counts[edge.color]++;
            }
            for (const auto& pair : color_counts) {
                if (pair.second > degree[i] / 2) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    // --- Pathfinding Algorithm ---
    // If all checks pass, try to find a valid tour.
    for (int start_node = 1; start_node <= N; ++start_node) {
        if (degree[start_node] == 0) continue;

        for (const auto& first_edge : adj[start_node]) {
            vector<int> path;
            vector<bool> visited_edge(M + 1, false);

            path.push_back(first_edge.id);
            visited_edge[first_edge.id] = true;

            int curr_node = first_edge.to;
            int prev_color = first_edge.color;

            // Greedily build the rest of the path
            while (path.size() < M) {
                bool found_next_edge = false;
                for (const auto& next_edge : adj[curr_node]) {
                    if (!visited_edge[next_edge.id] && next_edge.color != prev_color) {
                        path.push_back(next_edge.id);
                        visited_edge[next_edge.id] = true;
                        curr_node = next_edge.to;
                        prev_color = next_edge.color;
                        found_next_edge = true;
                        break;
                    }
                }
                if (!found_next_edge) {
                    break; // Stuck, this path is invalid.
                }
            }

            // If a full path was found, perform the final check.
            if (path.size() == M) {
                // Get the color of the last road from its ID.
                int last_edge_color = 0;
                int last_edge_id = path.back();
                // Find last edge details from the start node's adjacency list
                 for(const auto& edge : adj[start_node]){
                    if(edge.id == last_edge_id){
                        last_edge_color = edge.color;
                        break;
                    }
                }

                // Final check: first and last roads must have different colors.
                if (first_edge.color != last_edge_color) {
                    cout << start_node << endl;
                    for (int i = 0; i < path.size(); ++i) {
                        cout << path[i] << (i == path.size() - 1 ? "" : " ");
                    }
                    cout << endl;
                    return 0; // Solution found, exit.
                }
            }
        }
    }

    // If loops complete, no solution exists.
    cout << -1 << endl;

    return 0;
}