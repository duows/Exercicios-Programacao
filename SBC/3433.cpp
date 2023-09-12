#include <iostream>
#include <list>

using namespace std;

/*
1 - 4
2 - 4
3 - 4
4 - 4
5 - 4
6 - 4
7 - 4
8 - 4
9 - 4
10 - 16

maria < joao , joao precisa estourar

maria > joao , maria precisa 23

*/

int main() {

    bool disponivel = true;

    int cartas[13];

    int cartaNecessaria = 0;

    for (int i = 0; i < 13; i++) {
        cartas[i] = 0;
    }

    int joao = 0;
    int maria = 0;

    int n;
    cin >> n;

    if (n < 1 || n > 8) {
        return 0;
    }

    int j[2];

    for (int i = 0; i < 2; i++){
        cin >> j[i];
        joao += j[i];
        cartas[j[i] - 1]++;

        if (j[i] < 1 || j[i] > 13) {
            return 0;
        }
    }

    int m[2];

    for (int i = 0; i < 2; i++){
        cin >> m[i];
        maria += m[i];
        cartas[m[i] - 1]++;

        if (m[i] < 1 || m[i] > 13) {
            return 0;
        }
    }

    int c[8];

    for (int i = 0; i < n; i++){
        cin >> c[i];
        joao += c[i];
        maria += c[i];
        cartas[c[i] - 1]++;

        if (c[i] < 1 || c[i] > 13) {
            return 0;
        }
    }

    if (n == 8) {
            cout << "-1" << endl;
        } else {
        if (maria > 23){
            cout << "-1" << endl;
            return 0;
        } else {
            if (maria >= joao) {
                int cartaMinima = 23 - maria;

                for (int i = (cartaMinima); i < 13; i++){
                    if (cartas[i] < 4){
                        if (i > 10) {
                            cartaNecessaria = 10;
                        } else {
                            cartaNecessaria = i;
                        }
                        
                        disponivel = true;

                        break;
                    } else if (cartas[i] >= 4) {
                        disponivel = false;
                    }
                }

            } else {
                int cartaMinimaJoao = 24 - joao;

                for (int i = (cartaMinimaJoao); i < 13; i++) {
                    if (cartas[i] < 4){
                        if (i > 10) {
                            cartaNecessaria = 10;
                        } else {
                            cartaNecessaria = i + 1;
                        }
                        
                        disponivel = true;

                        break;
                    } else if (cartas[i] >= 4){
                        disponivel = false;
                    } 
                }

            }

            if (!disponivel) {
                cartaNecessaria = -1;
            }
        }
        
        cout << cartaNecessaria << endl;

    }
    
    return 0;
}