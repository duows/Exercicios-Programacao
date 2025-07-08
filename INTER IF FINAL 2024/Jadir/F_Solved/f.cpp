#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back


using namespace std;

int32_t main() {

  
  int L, M, A, V; cin >> L >> M >> A >> V;

  if (V <= L) {
    cout << 0 << endl;
    return 0;
  }

  int multa = ((V - L) * (A)) + M;
  cout << multa << endl;

  return 0;
}