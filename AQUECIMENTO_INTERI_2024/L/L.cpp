#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
011 000 010 111     011 000 101     100
C   A       TROCA   3   1   TROCA   D

CA 31D

ABCD EFGHIJKLMNOPQRSTUVWXYZ [{(
0123 456789!@#$%^&*-_=+,<.> ]})
100110010101110000110010001101011110111000101110011111101011

A   00001 = 1
B   00010 = 2
C   00011 = 3
D   00100 = 4
    00101 = 5
E   00110 = 6

11011 troca
11111 troca tbm

*/

int conveter(const string& bits) {
    return stoi(bits, nullptr, 2);
}

int main() {
    string conjunto1, conjunto2;
    getline(cin, conjunto1);
    getline(cin, conjunto2);

    string mensagemCodificada;
    getline(cin, mensagemCodificada);

    bool usandoConjunto1 = true;
    string mensagemDecodificada;
    
    for (size_t i = 0; i < mensagemCodificada.size(); i += 5) {
        string bloco = mensagemCodificada.substr(i, 5);
        
        if (bloco == "11011") {
            usandoConjunto1 = true;
        } else if (bloco == "11111") {
            usandoConjunto1 = false;
        } else {
            int index = conveter(bloco);
            
            if (usandoConjunto1) {
                mensagemDecodificada += conjunto1[index];
            } else {
                mensagemDecodificada += conjunto2[index];
            }
        }
    }

    cout << mensagemDecodificada << endl;

    return 0;
}
