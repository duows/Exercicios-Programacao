#include <iostream>

using namespace std;


#define N 1001

int main() {


    /**
     * 
     * Tabuleiro 1xN
     * 
     * N peças -> 1x1, 1x2,..., 1xN quadrados de tamanho.
     * 
     * Pecas[1..N] -> Vetor de 0s e 1s, 0: Não colocada. 1: Colocada
     * 
     * Separar em duas buscas: 
     * 
     * Esquerda de k
     * 
     * int lacunasEsq = e;
     * 
     * percorrer de "e" até 1 (Vetor peças):
     *  se peça não colocada e lacunasEsq >= i:
     *      lacunasEsq -= i;
     * 
     * 
     * Direita de k
     * 
     * int lacunasDir = n - (e+k)
     * 
     * Percorrer de "n-(e+k)" até 1 (Vetor peças):
     *      se peça não colocada e lacunasDir >= i: 
     *          lacunasDir -= i
     *      
     *      
     * int total = lacunasEsq+lacunasDir;
     * 
     * cout << total;
     * 
     * 
     * 
    */

    int n, k, e; 
    
    cin >> n >> k >> e;

    

    if (n < 1 || n > 1000 || k < 1 || k > n || e < 0 || e > (n-k)) {
        return 0;
    }

    int pecas[N];
    


    //Colocando a peça K na posição e:
    pecas[k] = 1;

    
    
    //Lado esquerdo do vetor:
    int lacunasEsq = e;

    for (int i = e; i >= 1; i--) {

        if (pecas[i] == 0 && lacunasEsq >= i) {
            pecas[i] = 1;
            lacunasEsq -= i;
        }

    }


    //Lado direito do vetor:
    int lacunasDir = n-(e+k);

    for (int i = n-(e+k); i >= 1; i--) {
        if (pecas[i] == 0 && lacunasDir >= i) {
            pecas[i] = 1;
            lacunasDir -= i;
        }
    }

    int total = lacunasDir+lacunasEsq;

    cout << total << endl;
    
    
   return 0;
}