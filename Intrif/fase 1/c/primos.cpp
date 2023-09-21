#include <iostream>
#include <string>
#include <math.h>

using namespace std;


bool verificaPrimo(int val) {

    bool primo = true;
    int max = sqrt(val);

    for (int i = 2; i <= max;i++) {
        if (val % i == 0) {
            primo = false;
        }
    }

    return primo;
    
}


int main() {

    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    if (n < 1 || n >= 100000) {
        return 0;
    }

    for (int i = 2; i<=n;i++) {
        if (verificaPrimo(i)) {
            if (i == 2) {
                cout << i;
            } else {
                cout << " " << i;
            }
            
        }
    }

    cout << endl;


    return 0;
}