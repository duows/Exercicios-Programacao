#include <bits/stdc++.h>

using namespace std;

/* macro para código mais rápido e para \n */
#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
#define endl '\n'

/* macro aleatórias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

/* macro para trabalhar com pair */
#define f first
#define s second

/* função para debugging */
#define dgb(x) cout << #x << " = " << x << endl;

/* define long long como ll */
typedef long long ll;

#define print(a) for(auto x : a) cout << x << endl

int main() { _

    stack<int> pilha;
    vi temp;
    
    while (true) {
        int aux; cin >> aux;
        
        if (aux == -1) {
            break;
        }
        
        if (aux == 0 && !pilha.empty()) {
            pilha.pop();
            temp.pop_back();
        } else if (aux != 0) {
            pilha.push(aux);
            temp.pb(aux);
        }
    }

    if (!temp.empty()) {
        for (int x : temp) {
            cout << x << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}

