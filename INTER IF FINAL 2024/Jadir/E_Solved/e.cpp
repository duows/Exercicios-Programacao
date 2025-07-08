#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back


using namespace std;

int32_t main() {

  freopen("input/2", "r",stdin);
  freopen("output.txt", "w",stdout);

  int N; cin >> N;

  unordered_map<char, int> digits = {
    { '0', 1 },
    { '1', 1 },
    { '2', 1 },
    { '3', 1 },
    { '4', 1 },
    { '5', 1 },
    { '6', 1 },
    { '7', 1 },
    { '8', 1 },
    { '9', 1 },
  };


  string s;
  
  
  for (int i = 0; i < N; i++) {
    cin >> s;

    string ans = "", acumulate = "";

    for (int i = 0; i < s.length(); i++) {
      if (digits[s[i]]) {
          acumulate += s[i];

          int code = stoi(acumulate);
          if (code >= 32) {
            ans += char(code);
            acumulate = "";
          }
      } else {

        if (acumulate != "") {
          int code = stoi(acumulate);
          ans += char(code);
        }

        acumulate = "";
        ans += s[i];
      }
    }

    if (acumulate != "") {
      int code = stoi(acumulate);
      ans += char(code);
    }

    cout << ans << endl;
  }

  return 0;
}