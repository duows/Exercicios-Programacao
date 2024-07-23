#include <iostream>

using namespace std;

int main()
{

    double v, t;

    cin >> v >> t;

    if (t/v < 0.7) {
        cout << "ETANOL" << endl;
    } else {
        cout << "GASOLINA" << endl;
    }

    return 0;
}