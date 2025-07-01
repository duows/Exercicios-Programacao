#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); 

#define endl '\n'


using namespace std;




int main() { _

    int N; cin >> N;

    int qtdeDivisores = 0, selected = 0;
    for (int i = 0; i < N; i++ ) {
        int num; cin >> num;

        if (i == 0) selected = num;

        int qtde = 0;
        int novo = 0;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                qtde++;
            }
        }

        if (qtde > qtdeDivisores) {
            selected = num;
            qtdeDivisores = qtde;
        } else if (qtde == qtdeDivisores) {
            selected = min(selected, num);
        }

    }


    cout << selected << endl;

    return 0;
}