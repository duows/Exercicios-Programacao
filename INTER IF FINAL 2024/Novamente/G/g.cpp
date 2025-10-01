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

int main() { _

  int b; cin >> b;

  string s1; cin >> s1;

  string s2; cin >> s2;

  double s; cin >> s;

  unordered_map<char, int> m;

  for (int i = 0; i < s1.length(); i++) {
    m[s1[i]] = i;
  }

  double res = 0.0;
  long long val = 0;
  for (int i = 0; i < s2.length(); i++) {
    val = val * b + m[s2[i]];
  }
  
  res = val * s;


  cout << fixed << setprecision(2) << res << endl;

	return 0;
}
