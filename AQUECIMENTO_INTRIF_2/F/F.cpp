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

int charToInt(char c) {
	int num = c - '0';
	return num;
}


int main() { _
	
	int n; cin >> n;
	
	vector<string> res;
	
	for (int i = 0; i < n; i++) {
		string doc; cin >> doc;
		int a=0, b=0, c=0, d=0, e=0, f=0, g=0, g_or=0;
		
		a = 20 * charToInt(doc[0]);
		b = 19 * charToInt(doc[1]);
		c = 17 * charToInt(doc[2]);
		d = 14 * charToInt(doc[4]);
		e = 10 * charToInt(doc[5]);
		f = 5  * charToInt(doc[6]);
		g_or = charToInt(doc[8]);
		
		if ((a == b && b == c && c == d && d == e && e == f && f == g) || doc.size() > 9 || doc.size() < 9)  {
			res.pb("CDN INVALIDO! ");
		} else {
			int sum = a + b + c + d + e + f;
			if ((sum % 11 == 0) || (sum % 11 == 1)) {
				g = 0;
			} else {
				g = 11 - (sum % 11);
			}
	
			if (g == charToInt(doc[8])) {
				res.pb("CDN VALIDO!");
			} else {
				res.pb("CDN INVALIDO! ");
			}
		}	
	}
	
	printv2(res);

	return 0;
}
