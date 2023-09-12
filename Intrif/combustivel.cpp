#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    float v;
    cin >> v;

    if (v < 0 || v > pow(10, 38))
    {
        return 0;
    }

    float t;
    cin >> t;

    if (t < 0 || t > pow(10, 38))
    {
        return 0;
    }

    float q = 0;

    if (v == 0)
    {
        cout << "GASOLINA" << endl;
    }
    else
    {
        if (t == 0)
        {
            cout << "ETANOL" << endl;
        }
        else
        {
            q = t / v;

            if (q < 0.7)
            {
                cout << "ETANOL" << endl;
            }
            else
            {
                cout << "GASOLINA" << endl;
            }
        }
    }

    return 0;
}