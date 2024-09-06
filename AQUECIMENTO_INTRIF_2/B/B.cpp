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

/* define long long como ll */
typedef long long ll;

#define print(a) { \
    bool first = true; \
    for (const auto& x : a) { \
        if (!first) cout << " "; \
        cout << x; \
        first = false; \
    } \
    cout << endl; \
}

int main() { _

    queue<string> O, N, S, L;
    string p = "";
    int atual = 0;

    while (cin >> p) {
        if (p == "-1") {
            atual = -1;
        } else if (p == "-2") {
            atual = -2;
        } else if (p == "-3") {
            atual = -3;
        } else if (p == "-4") {
            atual = -4;
        } else if (p == "0") {
            break;
        } else {
            // Adiciona à fila correta
            if (atual == -1) O.push(p);
            else if (atual == -2) S.push(p);
            else if (atual == -3) N.push(p);
            else if (atual == -4) L.push(p);
        }
    }

    vector<string> ord;
	bool ult = false;

	while (!S.empty() or !N.empty() or !O.empty() or !L.empty()) {
		
		if (!O.empty()) {
			ord.pb(O.front());
			O.pop();
		}

		if (!ult) {
			if (!N.empty()) {
				ord.pb(N.front());
				N.pop();
			}
			
			if (!S.empty()) {
				ord.pb(S.front());
				S.pop();
				ult = false;
			} else {
				ult = true;
			}
		} else {
			if (!S.empty()) {
				ord.pb(S.front());
				S.pop();
			}
			
			if (!N.empty()) {
				ord.pb(N.front());
				N.pop();
				ult = true;
			} else {
				ult = false;	
			}
			
		}
		
		
		if (!L.empty()) {
			ord.pb(L.front());
			L.pop();
		}
		
	}

	print(ord);

    return 0;
}

