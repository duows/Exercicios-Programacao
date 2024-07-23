
#include <iostream>

using namespace std;


//RUNTIME ERROR ???

long long int f(long long int x) {
    while (x < 10000000) {
        x += 13 * 3;
    }
    return x - 3;
}

int main() {

    long long int N; cin >> N;


    cout << f(N) << endl;

    return 0;
}