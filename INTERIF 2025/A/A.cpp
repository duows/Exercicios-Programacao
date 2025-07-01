#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); 

#define endl '\n'


using namespace std;




int main() { _

    int N; cin >> N;

    vector<int> p;

    for (int i = 0; i < N; i++) {
        int n; cin >> n;

        p.push_back(n);
    }

    int V; cin >> V;

    sort(p.begin(), p.end(), [](const int &a, const int &b) {
        return a > b;
    });


    int atual = V;
    int cont = 0;
    for (int i = 0; i < p.size(); i++) {
        if (atual >= p[i]) {
            cont+= atual/p[i];
            atual %= p[i];
        }
    }

    if (atual != 0) {
        cout << "frustraka" << endl;
    } else {
        cout << cont << endl;
    }
}