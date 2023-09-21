#include <iostream>
#include <string>

using namespace std;


int main() {

    int n1, n2, n3, n4;

    cin >> n1 >> n2 >> n3 >> n4;

    if (n2 > n1 && n3 > n2 && (n1+n2+n3) == n4) {
        cout << "LIBERADO" << endl;
    } else {
        cout << "NEGADO" << endl;
    }

    return 0;
}