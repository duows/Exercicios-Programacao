#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

struct Estrada {
    int to;
    int cor;
    int id;
    bool visitada = false;
};

void procurarCaminho(int cidadeAtual, map<int, vector<Estrada>>& adj, vector<int>& caminhoAtual, int corAnterior, int estradas, int M, int cidadeInicio, bool &achou, int &primeiraCor) {
    if (achou) return;

    if (estradas == M) {
        if (cidadeAtual == cidadeInicio && primeiraCor != corAnterior) {
            achou = true;
        }
        return;
    }

    for (int i = 0; i < adj[cidadeAtual].size(); i++) {
        auto &e = adj[cidadeAtual][i];

        if (e.visitada || e.cor == corAnterior) continue;

        
        e.visitada = true;
        for (auto &rev : adj[e.to]) {
            if (rev.to == cidadeAtual && rev.id == e.id) {
                rev.visitada = true;
                break;
            }
        }

        if (estradas == 0) primeiraCor = e.cor;

        caminhoAtual.push_back(e.id);
        procurarCaminho(e.to, adj, caminhoAtual, e.cor, estradas + 1, M, cidadeInicio, achou, primeiraCor);
        if (achou) return;
        caminhoAtual.pop_back();

        
        e.visitada = false;
        for (auto &rev : adj[e.to]) {
            if (rev.to == cidadeAtual && rev.id == e.id) {
                rev.visitada = false;
                break;
            }
        }
    }
}

int main() { _
    int N, M, K;
    cin >> N >> M >> K;

    map<int, vector<Estrada>> adj;

    for (int i = 1; i <= M; i++) {
        int I, J, C;
        cin >> I >> J >> C;

        adj[I].push_back({J, C, i});
        adj[J].push_back({I, C, i});
    }

    // Verificar se todos os vértices têm grau par
    for (auto &it : adj) {
        if (it.second.size() % 2 != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> caminho;
    bool achou = false;
    int inicio = -1;

    for (auto &it : adj) {
        inicio = it.first;
        int primeiraCor = -1;
        procurarCaminho(it.first, adj, caminho, -1, 0, M, it.first, achou, primeiraCor);
        if (achou) break;
    }

    if (achou) {
        cout << inicio << endl;
        for (int id : caminho) cout << id << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}