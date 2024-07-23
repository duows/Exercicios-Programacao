#include <iostream>

using namespace std;

int main()
{

    int a, b, c;

    cin >> a >> b >> c;

    int s;
    double dt;

    dt = (a / (b * 1000.0));

    s = c / dt;

    cout << s << endl;

    return 0;
}