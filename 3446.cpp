#include <iostream>

using namespace std;

int main()
{

    /*
    n -> tabuleiro de 1xN quadrados

    k -> peça de 1xK quadrados

    e -> qtde de quadrados vazios a esquerda de k

    exemplo

    6 2 2

     1 2 3 4 5 6
    | | | | | | |

     1 2 3 4 5 6
    | | |x|x| | |

    só é possivel colocar a peça 1x1 pois a 1x2 já está em uso

    receber peça
    vetor tabuleiro[n]

    6 2 2

    peça 1x2 com e = 2

    acrescenta 1 de i = e + 1 até i = k

    e1 e2 e3 e4 e5 e6
    0  0  0  0  0  0

    i = e + 1

    e1 e2 e3 e4 e5 e6
    0  0  1  0  0  0



    aaa

    */

    int n;

    int k;

    int e;

    cin >> n >> k >> e;

    if (n < 1 || n > 1000) {
        return 0;
    }

    int tab[n];

    for (int i = 0; i < n; i++) {
        tab[i] = 0;
    }

    if (k < 1 || k > n) {
        return 0;
    }

    if (e < 0 || e > (n - k)) {
        return 0;
    }

    /*
    e = 2
    k = 2

    0 0 0 0 0 0
    0 1 2 3 4 5
    */

    for (int i = (e); i < (e+k); i++) {
        tab[i] = 1;
    }

    

    return 0;
}