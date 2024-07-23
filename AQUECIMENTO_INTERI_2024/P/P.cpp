#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string str;
    int moeda_25, moeda_10, moeda_5, moeda_1;
    
    cin >> str;
    str = str.substr(2);
    
    double preco = stod(str);
    int preco_pacote = round(preco * 100);

    cin >> moeda_25 >> moeda_10 >> moeda_5 >> moeda_1;

    int total_moedas = moeda_25 * 25 + moeda_10 * 10 + moeda_5 * 5 + moeda_1;
    
    int pacotes = total_moedas / preco_pacote;
    int sobra = total_moedas - preco_pacote;

    int aux = 0;

    while (aux < (pacotes * preco_pacote)) {
        if (aux + 25 <= total_moedas && moeda_25 > 0) {
            aux += 25;
            moeda_25--;
        } else if (aux + 10 <= total_moedas && moeda_10 > 0) {
            aux += 10;
            moeda_10--;
        } else if (aux + 5 <= total_moedas && moeda_5 > 0) {
            aux += 5;
            moeda_5--;
        } else if (aux + 1 <= total_moedas && moeda_1 > 0) {
            aux += 1;
            moeda_1--;
        }
    }

    int tot_moedas = moeda_25 + moeda_10 + moeda_5 + moeda_1;

    cout << pacotes << endl;
    cout << tot_moedas << endl;

    return 0;
}
