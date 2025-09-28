#include <bits/stdc++.h>

using namespace std;

/*macro para código mais rapido e para \n*/
#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
//^comentar _ para degubar código
#define endl '\n'


/* macro aleatorias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

#define printv(a) do {                             \
    for (size_t i = 0; i < (a).size(); ++i) {      \
        cout << (a)[i];                            \
        if (i < (a).size() - 1)                    \
            cout << " ";                           \
    }                                              \
    cout << endl;                                  \
} while(0)

#define printv2(a) do {                            \
    for (auto x : (a))                             \
        cout << x << endl;                         \
} while(0)

#define print_matrix(m, l, c) do {                 \
    for (int i = 0; i < (l); ++i) {                \
        for (int j = 0; j < (c); ++j) {            \
            cout << (m)[i][j] << " ";              \
        }                                          \
        cout << endl;                              \
    }                                              \
} while(0)


/* macro para trabalhar com pair*/
#define f first
#define s second

/* funcao para debugging*/
#define dgb(x) cout << #x << " = " << x << endl;

/* define long long como ll */
typedef long long ll;

/* define constantes infinitas */
//const int INF = 0x3f3f3f3f;
//const ll LINF = 0x3f3f3f3f3f3f3f3fll;

/*

5 5
k = 5

5   4   3   2   1   INF
[ ]
5   4   3   2   1 -> prefixo

1   1   1   1   1

*/

#define MAXN 100100

const int INF = 0x3f3f3f3f;

int main() { _
    int n, k;
    int v[MAXN], pref[MAXN], suf[MAXN];
    
	cin >> n >> k;

    pref[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = min(pref[i - 1], v[i]);
    }

    suf[n + 1] = INF;
    for(int i = n; i > 0 ; i--) {
        suf[i] = min(suf[i + 1], v[i]);
    }

    multiset<int> s;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        s.insert(v[i] + i);

        /* 3 3 1 3 3 3 
        
        1 6 7 8
        */

        if (i - k > 0) {
            s.erase(s.find(v[i - k] + i - k));
        }

        int r = *s.begin() - i + k;

        if (i - k > 0) {
            r = min(r, pref[i - k]);
        }

        if (i < n) {
            r = min(r, suf[i + 1]);
        }

        res = max(res, r);
    }

    cout << res << endl;

	return 0;
}
