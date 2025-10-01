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

  int x, y; cin >> x >> y;

  vector<int> v;
  for (int i = 0; i < x; i++) {
    int n; cin >> n;
    v.push_back(n);
  }

  int left = 0, right = y-1;

  int avisos = 0;
  while (right < (v.size() - 1)) {
    vector<int> aux;

    for (int i = left; i <= right; i++) {
      aux.push_back(v[i]);
    }

    sort(aux.begin(), aux.end());

    int mediana = aux[y / 2];

    if ((mediana * 2) <= v[right+1]) {
      avisos++;
    }

    right++;
    left++;
  }


  cout << avisos << endl;



	return 0;
}
