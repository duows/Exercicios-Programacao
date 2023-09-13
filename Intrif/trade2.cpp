#include <math.h>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int binaryToDecimal(string binary)
{
    int decimal = 0;
    int binaryLength = binary.length();

    for (int i = 0; i < binaryLength; i++)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, binaryLength - 1 - i);
        }
    }

    return decimal;
}

int main()
{

    string texto;
    getline(cin, texto);

    texto.erase(std::remove_if(texto.begin(), texto.end(), ::isspace), texto.end());

    int cont = 0;
    string cadeia;
    vector<string> caracteres;

    for (char c : texto)
    {
        int cod = (int)c;
        if ((cod >= 65 && cod <= 90))
        {
            cadeia += "1";
        }
        else
        {
            if ((cod >= 97 && cod <= 122))
            {
                cadeia += "0";
            }
            else
            {
                continue;
            }
        }

        if (cont == 7)
        {
            caracteres.push_back(cadeia);
            cadeia = "";
            cont = 0;
        }
        else
        {
            cont++;
        }
    }

    string finalAqui;
    for (string s : caracteres)
    {
        if (s.length() == 8)
        {
            int dec = binaryToDecimal(s);
            char letra = static_cast<char>(dec);
            finalAqui += letra;
        }
    }
    cout << finalAqui << "" << endl;

    return 0;
}