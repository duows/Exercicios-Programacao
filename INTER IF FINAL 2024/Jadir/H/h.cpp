#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back


using namespace std;

int32_t main() {

  int B; cin >> B;

  unordered_map<char, int> c;
  string s; cin >> s;
  
  for (int i = 0; i < s.length(); i++) {
    c[s[i]] = i;
  }

  string s2; cin >> s2;

  double S; cin >> S;

  double valueBase = 0;
  for (int i = 0; i < s2.length(); i++) {
    int value = c[s2[i]];
    valueBase += value * pow(s.length(), s2.length() - i - 1);
  }

  cout << fixed << setprecision(2) << valueBase * S << endl;


  return 0;
}