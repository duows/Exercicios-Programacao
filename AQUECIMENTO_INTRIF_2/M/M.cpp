#include <bits/stdc++.h>

using namespace std;

/* macro para código mais rápido e para \n */
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/* macro aleatórias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

/* macro para trabalhar com pair */
#define f first
#define s second
#define dgb(x) cout << #x << " = " << x << endl;

/* define long long como ll */
typedef long long ll;

int countSeries(const vector<int>& v, int targetWeight) {
    int serie = 0;
    int n = v.size();
    
    for (int i = 0; i < n; i++) {
        int soma = 0;
        for (int j = i; j < n; j++) {
            soma += v[j];
            if (soma == targetWeight) {
                serie++;
            } else if (soma > targetWeight) {
                break; // Se a soma exceder o peso alvo, não há razão para continuar somando
            }
        }
    }
    
    return serie;
}

int main() { _
    vector<int> v;
    int targetWeight, qtd; cin >> targetWeight >> qtd;
    
    for (int i=0; i < qtd; i++) {
    	int aux; cin >> aux;
    	v.pb(aux);
	}

    
    int res = countSeries(v, targetWeight);
    
    if (res == 0) {
    	cout << "nenhuma" << endl;
	} else if (res == 1) {
		cout << "1 serie" << endl;
	} else {
		cout << res << " series" << endl;
	}

    return 0;
}

