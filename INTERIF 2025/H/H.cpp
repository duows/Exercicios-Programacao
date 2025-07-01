#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); 

#define endl '\n'


using namespace std;




int main() { _

    int L, C, x, y, D; cin >> L >> C >> x >> y >> D;

    int H; cin >> H;
    int dentro = 0;
    for (int i = 0; i < H; i++) {
        double x1, y1; cin >> x1 >> y1;



        double dist = sqrt(pow(abs(x - x1), 2) + pow(abs(y - y1), 2) );

        if ( dist <= D ) {
            cout << "Uma casinha no meio de todas" << endl;
            return 0;
        }
    }

    cout << "Uma casinha no meio do nada" << endl;
    return 0;

}