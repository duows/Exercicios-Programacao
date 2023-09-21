#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string texto;
    getline(cin, texto);

    string maiuscula = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string minuscula = "abcdefghijklmnopqrstuvwxyz";

    vector<int> mensagem;
    int indice = 7;
    int decifra = 0;

    for (char letra : texto)
    {
        if (maiuscula.find(letra) != string::npos)
        {
            decifra += 1 << indice;
            indice -= 1;
        }
        else if (minuscula.find(letra) != string::npos)
        {
            indice -= 1;
        }

        if (indice == -1)
        {
            indice = 7;
            mensagem.push_back(decifra);
            decifra = 0;
        }
    }

    
    cout << endl;
    // write vetor mensagem
    for (int i = 0; i < mensagem.size()-1; i++) {
        cout << mensagem[i] << " ";
    }
    



    for (int letra : mensagem)
    {
        if (letra != 0)
        {
            cout << static_cast<char>(letra);
        }
    }
    cout << endl;

    return 0;
}