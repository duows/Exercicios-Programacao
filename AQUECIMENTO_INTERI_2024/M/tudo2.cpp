#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; 
    cin >> N >> M;
    int L; 
    cin >> L;

    vector<vector<int>> fluxos(N, vector<int>(L, 0));

    // Lê os valores e separa nos respectivos vetores de fluxo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            int valor; 
            cin >> valor;
            fluxos[i][j] = valor;
        }
    }

    // Imprime fluxos para verificar
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            cout << fluxos[i][j] << " ";
        }
        cout << endl;
    }

    // Vetor de prefixo somado para cada fluxo
    vector<vector<long long>> prefixSum(N, vector<long long>(L + 1, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= L; j++) {
            prefixSum[i][j] = prefixSum[i][j - 1] + fluxos[i][j - 1];
        }
    }

    // Imprime prefixSum para verificar
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= L; j++) {
            cout << prefixSum[i][j] << " ";
        }
        cout << endl;
    }

    int quadroAtual = 1;
    
    for (int posInicial = 0; posInicial < L; posInicial += M) {
        long long int somaQuadro = 0;

        for (int i = 0; i < N; i++) {
            int posFinal = min(posInicial + M, L);
            somaQuadro += prefixSum[i][posFinal] - prefixSum[i][posInicial];
        }

        long long int mod = somaQuadro % 256;
        cout << mod << endl;

        quadroAtual++;
    }

    return 0;
}
