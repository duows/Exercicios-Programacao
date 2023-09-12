#include <iostream>
#include <cctype>

using namespace std;

#define S 50

int main()
{

    int vet[26];
    
    
        
    string texto;
    cin >> texto;

    for (char &c : texto)
    {
        c = tolower(c);

        if (vet[c] == 0)
        {
            vet[c] = vet[c] + 1;
        }
        else
        {
            vet[c] = vet[c] - 1;
        }
    }

    int cont = 0;

    for (int num : vet)
    {

        cout << num << " ";

        if (num != 0)
        {
            cont++;
        }
    }
    
    cout << endl;

    if (texto.length() % 2 == 0)
    {

        if (cont == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        if (cont == 1)
        {

            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}