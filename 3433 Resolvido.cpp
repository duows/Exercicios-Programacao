#include <iostream>

using namespace std;

int main() {

    int n; cin >> n;

    int cartas[14];
    int pontos[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    for (int i=0;i<14;i++) {
        cartas[i]=0;
    }

    if (n<1 || n > 8) {
        return 0;
    }

    int num1, num2;

    //Descrevendo as cartas iniciais do João
    cin >> num1 >> num2;
    int J = pontos[num1]+pontos[num2];
    cartas[num1]++;
    cartas[num2]++;


    //Descrevendo as cartas iniciais da Maria
    cin >> num1 >> num2;
    int M = pontos[num1]+pontos[num2];
    cartas[num1]++;
    cartas[num2]++;


    
    if (M >= 23 || J >= 23) {
        cout << -1 << endl;
        return 0;
    }


    for (int i=1; i<=n; i++) {

        int carta; cin >> carta;
        
        if (carta < 1 || carta > 13 || cartas[carta] == 4) {
            return 0;
        }

        cartas[carta]++;
        J += pontos[carta];
        M += pontos[carta];
    }

    //cout << "João: " << J << "\n Maria: " << M;

    int resp = -1;

    if (M >= J) {

        //Maria maior ou igual ao João, nesse caso ela deverá fazer os 23 pontos.
        int cartaNecessaria = 23-M;

        if (cartas[cartaNecessaria] < 4) {
            
            if ( (M + pontos[cartaNecessaria]) == 23) {
                resp = pontos[cartaNecessaria];
            }

        }

    } else {

        //João maior que Maria, logo ele deverá estourar para que Maria vença
        for (int i= 1; i <= 13; i++) {

            if (cartas[i] < 4 && (J + pontos[i]) > 23 && (M + pontos[i]) <= 23) {

                resp=i;
                break;
                
            } 

        }

    }

    cout << resp << endl;


    return 0;
}
