#include <iostream>
#include <locale.h>
#include <string>

using namespace std;


int main() {
    
    setlocale(LC_ALL, "Portuguese");


    int D; cin >> D;

    if (D < 1 || D > 1000) {
        return 0;
    }

    string depositos[D+1];

    for (int i = 0; i <= D; i++) {
        cin >> depositos[i]; //Primeiro depósito é o saldo atual.

        string sub = depositos[i].substr(0, 2);

        if (sub == "R$") {

            depositos[i] = depositos[i].replace(0, 2, "");
            
            

            if ( depositos[i].length() < 4 || ( depositos[i].at(1) != '.' && depositos[i].at(2) != '.' )) {
                //Caso não tenha 1 ou 2 dígitos antes da vírgula.
                return 0;
            }


        } else {
            return 0;
        }
    }

    int cont = 0;

    float numeros[D+1];
    
    for (string s : depositos) {

        numeros[cont] = stof( s.substr(s.length()-2, 2) );
        
        cont++;
    }

    int conta = numeros[0];

    int atrasos = 0;
    
    for (int i = 1; i <= D;i++) {
        
        conta += numeros[i];
        
        if (conta%100 != 0) {
            atrasos++;
        }
        
    }
    
    cout << atrasos << endl;

    

    return 0;
}