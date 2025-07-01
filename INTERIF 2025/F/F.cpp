#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); 

#define endl '\n'


using namespace std;




int main() { _

    unordered_map<string, int> contSeqs;

    unordered_map<int, vector<string>> fim;

    string s;

    char aux[] = { ',', ';', '.', ':', '"', '!', '?' };
    while (cin >> s) {

        string s2 = "";
        for (char &c : s){
            int add = 1;
            for (int i = 0; i < 7; i++) {
                if (c == aux[i]) {
                    add = 0;
                    break;
                }
            }

            if (add == 1) {
                s2 += tolower(c);
            }
        }
        contSeqs[s2]+= 1;
    }

    vector<int> ord;
    for (auto &it : contSeqs) {

        int tem = 0;
        for (int i = 0; i < ord.size(); i++) {
            if (ord[i] == it.second) {
                tem = 1;
            }
        }

        if (tem == 0) {
            ord.push_back(it.second);
        }
        fim[it.second].push_back(it.first);
    }

    sort(ord.begin(), ord.end(), [](const int &a, const int &b) {
        return a > b;
    });

    for (auto &i : ord) {
       if (fim[i].size() == 0) continue;
        cout << i << ": ";

        sort(fim[i].begin(), fim[i].end());
        for (int j = 0; j < fim[i].size(); j++) {
            cout << fim[i][j];

            if (j < fim[i].size() - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }
}