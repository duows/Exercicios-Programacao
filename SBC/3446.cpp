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

    if (n < 1 || n > 1000)
    {
        return 0;
    }

    int tab[n];

    int pecas[n];

    for (int i = 0; i < n; i++)
    {
        pecas[i] = i;
    }

    pecas[0] = 0;
    pecas[k] = 0;

    for (int i = 0; i < n; i++)
    {
        tab[i] = 0;
    }

    if (k < 1 || k > n)
    {
        return 0;
    }

    if (e < 0 || e > (n - k))
    {
        return 0;
    }

    /*
    e = 2
    k = 2

    0 0 0 0 0 0
    0 1 2 3 4 5
    */

    int espBrancoEsq = 0;
    int espBrancoDir = 0;

    for (int i = 0; i < n; i++)
    {
        if (i >= e && i < (e + k))
        {
            tab[i] = 1;
        }
        else
        {
            if (i < e)
            {
                espBrancoEsq++;
            }
            else
            {
                espBrancoDir++;
            }
        }
    }

    int espBranco = 0;

    if (pecas[espBrancoEsq] != 0)
    {
        pecas[espBrancoEsq] = 0;
        espBrancoEsq = 0;
    }
    if (pecas[espBrancoDir] != 0)
    {
        pecas[espBrancoDir] = 0;
        espBrancoDir = 0;
    }

    for (int i = (n - 1); i >= 0; i--)
    {
        if (pecas[i] != 0)
        {
            if (pecas[i] == espBrancoEsq)
            {
                pecas[i] = 0;
                espBrancoEsq = 0;
            }
            else if (pecas[i] == espBrancoDir)
            {
                pecas[i] = 0;
                espBrancoDir = 0;
            }
            else if (pecas[i] < espBrancoEsq)
            {
                espBrancoEsq = espBrancoEsq - pecas[i];
                pecas[i] = 0;
            }
            else if (pecas[i] < espBrancoDir)
            {
                espBrancoDir = espBrancoDir - pecas[i];
                pecas[i] = 0;
            }
        }
    }

    espBranco = espBrancoDir + espBrancoEsq;

    cout << espBranco << endl;

    /*
    0 -> é vazio, tenho peça i

    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << pecas[i] << " ";
    }
*/

    return 0;
}