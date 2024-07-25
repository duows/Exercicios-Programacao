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

    int quadroAtual = 1;
    
    for (int posInicial = 0; posInicial < L; posInicial += M) {
        long long int somaQuadro = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int pos = posInicial + j;
                if (pos < L) {
                    cout << fluxos[i][pos] << endl;
                    somaQuadro += fluxos[i][pos];
                }
            }
        }

        long long int mod = somaQuadro % 256;
        cout << mod << endl;

        quadroAtual++;
    }

    return 0;
}
