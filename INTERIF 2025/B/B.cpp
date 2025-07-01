#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); 

#define endl '\n'


using namespace std;




int main() { _

    string s; cin >> s;

    int pivot = 0, maxDistance = 1;
    vector<int> v;

    int cont = pivot;
    
    while (true) {
        if (cont >= s.length()) {
            v.push_back(cont - pivot);
            break;
        }

        if (s[cont] == s[cont+1] ) {
            v.push_back(cont - pivot + 1);
            pivot = cont+1;
        } 

        cont++;
    }

    int maxNum = 0;
    for (int i = 0; i < v.size(); i++) {
        maxNum = max(v[i], maxNum);
    }

    cout << maxNum << endl;

    return 0;
}