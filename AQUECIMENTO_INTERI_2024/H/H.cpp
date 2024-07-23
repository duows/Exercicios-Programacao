#include <iostream>

using namespace std;

int main()
{

    double n, v;

    cin >> n >> v;

    double p; 

    p = 100 * (v / n);

    printf("%.1f%%\n", p);

    return 0;
}