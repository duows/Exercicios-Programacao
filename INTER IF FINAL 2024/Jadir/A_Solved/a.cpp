#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back


using namespace std;

int32_t main() {

  freopen("test/input/9", "r", stdin);
  freopen("output.txt", "w", stdout);

  int x;
  int y;
  cin >> x >> y;

  unordered_map<int, int> freqs;
  for (int i = 0; i < y; i++) {
      int val;
      cin >> val;

      int need = x - val;
      if (freqs.count(need)) {
          int j = freqs[need];
          if (j < i) 
              cout << j << ' ' << i << "\n";
          else 
              cout << i << ' ' << j << "\n";
          break;
      }

      freqs[val] = i;
  }

  return 0;
}