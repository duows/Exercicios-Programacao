#include <iostream>
#include <math.h>

using namespace std;

int funcRafael(int x, int y) {
    return ((9*(pow(x,2))) + pow(y,2));
}

int funcBeto(int x, int y) {
    return (2*(pow(x,2)) + (25*(pow(y,2))));
}

int funcCarlos(int x, int y) {
    return (((-100)*x) + (pow(y,3)));
}


int main()
{

    int x, y;

    cin >> x >> y;

    if (x < 1 || y > 100) {
        return 0;
    }

    if (funcRafael(x,y) > funcBeto(x,y)){
        if (funcRafael(x,y) > funcCarlos(x,y)) {
            cout << "Rafael ganhou" << endl;
        } else {
            cout << "Carlos ganhou" << endl;
        }
    } else {
        if (funcBeto(x,y) > funcCarlos(x,y)){
            cout << "Beto ganhou" << endl;
        } else{
            cout << "Carlos ganhou" << endl;
        }
    }


    return 0;
}