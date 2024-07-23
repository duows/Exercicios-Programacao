#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    vector<char> str;
    char c;

    while (true)
    {
        c = cin.get();

        if (c == '\n')
        {
            break;
        }

        if (isalpha(c) && !isupper(c))
        {
            str.push_back(c);
        }
    }

    /*
    FRIO - 4
    MUITO FRIO - 10
    EXTREMAMENTE FRIO - 17
    QUENTE - 6*/

    switch (str.size())
    {
    case 4:
        cout << "24" << endl;
        break;
    case 11:
        cout << "20" << endl;
        break;
    case 17:
        cout << "18" << endl;
        break;
    case 6:
        cout << "28" << endl;
        break;
    default:
        cout << "COMANDO INVALIDO" << endl;
        break;
    }
    
    return 0;
}