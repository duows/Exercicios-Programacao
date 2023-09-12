#include <iostream>

using namespace std;

int funcX(int x) {
    return x-3;
}

int funcRecDificil(int x){
    if (x >= 10000000) {
        return funcX(x);
    } else {
        while (x < 10000000) {
            x += 13;
        }

        return funcX(x);
    }
}



int main()
{

    int x; cin >> x;

    if (x <= 0 || x >= 20000000) {
        return 0;
    }

    if (x >= 10000000) {
        cout << funcX(x) << endl;
    } else {
        cout << funcRecDificil(x) << endl;
    }
    
    return 0;
}