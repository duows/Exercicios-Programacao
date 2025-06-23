#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main() { _

  float a, b, c;  cin >> a >> b >> c;

  if (a > b && a > c) {
    cout << "Equipe A ganhou" << endl;
  } else if (b > a && b > c) {
    cout << "Equipe B ganhou" << endl;
  } else if (c > a && c > b) {
    cout << "Equipe C ganhou" << endl;
  } else {
    cout << "Empatou" << endl;
  }
  return 0;
}
