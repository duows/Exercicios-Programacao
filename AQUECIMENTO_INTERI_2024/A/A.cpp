#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

// Estrutura para armazenar as arestas do grafo
struct Aresta {
    string destino;
    int distancia;
};

// Estrutura para armazenar informações do nó na fila de prioridade
struct No {
    int distancia;
    int quantidade_nos;
    string nome;
    vector<string> caminho;
    
    bool operator>(const No& outro) const {
        if (distancia == outro.distancia) {
            return quantidade_nos > outro.quantidade_nos; // Minimizar número de nós em caso de empate
        }
        return distancia > outro.distancia;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    string origem, destino;
    cin >> origem >> destino;
    
    map<string, vector<Aresta>> grafo;
    
    for (int i = 0; i < M; ++i) {
        string u, v;
        int d;
        cin >> u >> v >> d;
        grafo[u].push_back({v, d});
    }
    
    priority_queue<No, vector<No>, greater<No>> fila_prioridade;
    fila_prioridade.push({0, 1, origem, {origem}});
    
    map<string, pair<int, int>> melhor;
    melhor[origem] = {0, 1}; // {menor_distancia, menor_quantidade_de_nos}
    
    while (!fila_prioridade.empty()) {
        No atual = fila_prioridade.top();
        fila_prioridade.pop();
        
        if (atual.nome == destino) {
            cout << "Percurso: ";
            for (size_t i = 0; i < atual.caminho.size(); ++i) {
                if (i > 0) {
                    cout << "--> ";
                }
                cout << atual.caminho[i];
            }
            cout << endl;
            return 0;
        }
        
        for (const Aresta& aresta : grafo[atual.nome]) {
            int nova_distancia = atual.distancia + aresta.distancia;
            int nova_quantidade = atual.quantidade_nos + 1;
            
            if (melhor.find(aresta.destino) == melhor.end() || 
                melhor[aresta.destino].first > nova_distancia || 
                (melhor[aresta.destino].first == nova_distancia && melhor[aresta.destino].second > nova_quantidade)) {
                
                melhor[aresta.destino] = {nova_distancia, nova_quantidade};
                vector<string> novo_caminho = atual.caminho;
                novo_caminho.push_back(aresta.destino);
                
                fila_prioridade.push({nova_distancia, nova_quantidade, aresta.destino, novo_caminho});
            }
        }
    }
    
    return 0;
}
