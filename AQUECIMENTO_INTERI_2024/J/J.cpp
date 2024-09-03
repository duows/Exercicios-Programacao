
// Exercício Pega Varetas

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, vector<int>>> casos;
    
    // Ler todos os casos de teste
    while (true) {
        int n;
        cin >> n;
        if (n == -1) {
            break;
        }

        vector<int> jogadas;
        int valor;

        // Ler os valores da linha de jogadas
        while (cin >> valor) {
            if (valor == -1) {
                break;
            }
            jogadas.push_back(valor);
        }

        casos.emplace_back(n, jogadas);
    }

    // Processar e imprimir todos os casos de teste
    int rodada = 1;
    int total_casos = casos.size();

    for (const auto& caso : casos) {
        int n = caso.first;
        const vector<int>& jogadas = caso.second;

        int pontos[3] = {0, 0, 0};
        int jogador_atual = n - 1;

        for (int jogada : jogadas) {
            if (jogada == 0) {
                jogador_atual = (jogador_atual + 1) % 3;
            } else if (jogada == -1) {
                break;
            } else {
                switch (jogada) {
                    case 1:
                        pontos[jogador_atual] += 5;
                        break;
                    case 2:
                        pontos[jogador_atual] += 10;
                        break;
                    case 3:
                        pontos[jogador_atual] += 15;
                        break;
                    case 4:
                        pontos[jogador_atual] += 20;
                        break;
                    case 5:
                        pontos[jogador_atual] += 50;
                        break;
                }
            }
        }

        cout << "RODADA " << rodada << endl;

        int max_pontos = *max_element(pontos, pontos + 3);
        vector<int> ganhadores;

        for (int i = 0; i < 3; ++i) {
            if (pontos[i] == max_pontos) {
                ganhadores.push_back(i + 1);
            }
        }

        if (ganhadores.size() > 1) {
            cout << "Empate com " << max_pontos << " pontos" << endl;
            cout << "Jogador ";
            for (size_t i = 0; i < ganhadores.size(); ++i) {
                if (i > 0) {
                    cout << ", Jogador ";
                }
                cout << ganhadores[i];
            }
            cout << endl;
        } else {
            cout << "Ganhador com " << max_pontos << " pontos" << endl;
            cout << "Jogador " << ganhadores[0] << endl;
        }

        if (rodada < total_casos) {
            cout << endl;
        }

        rodada++;
    }

    return 0;
}
