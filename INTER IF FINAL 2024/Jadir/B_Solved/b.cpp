#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back


using namespace std;

int32_t main() {

  int X, Y; cin >> X >> Y;

  vector<int> operacoes;
  for (int i = 0; i < X; i++) {
    int n; cin >> n;
    operacoes.pb(n);
  } 
  
  
  int left = 0, right = Y - 1, avisos = 0;
  while (right < operacoes.size() - 1) {

    vector<int> temp;
    for (int i = left; i <= right; i++) {
      temp.pb(operacoes[i]);
    }

    sort(temp.begin(), temp.end());

    int mediana = temp[ceil(temp.size() / 2)];

    if (operacoes[right+1] >= (mediana*2)) ++avisos;

    ++right;
    ++left;
  }

  cout << avisos << endl;
  return 0;
}