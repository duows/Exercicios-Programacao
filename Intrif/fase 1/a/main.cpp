#include <iostream>
#include <string>

using namespace std;


int main() {

    string vogais = "aeiouAEIOU";

    string texto;

    getline(cin, texto);

    if (texto.length() < 1 || texto.length() > 20) {
        return 0;
    }

    int cont = 0;

    for (char c : texto) {
        if (vogais.find(c) < vogais.length()) {
            cont++;
        }
    }

    int res = cont%3;

    cout << "frasco " << res << endl;


    return 0;
}