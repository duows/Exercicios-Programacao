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

  int N; cin >> N;


  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    string aux, res = "";

    for (int j = 0; j < s.length(); j++) {

      if ( isdigit(s[j]) ) {
        // Se é um dígito
        aux += s[j];
        if (aux.length() == 3) {
          int n = stoi(aux);
          res += static_cast<char>(n);
          aux = "";
        } 
      } else {

        if (aux.length() > 0) {
          int n = stoi(aux);
          res += static_cast<char>(n);
          aux = "";
        }

        res += s[j];
      }
    }

    if (aux.length() > 0) {
      int n = stoi(aux);
      res += static_cast<char>(n);
    }

    cout << res << endl;
  }

	return 0;
}
