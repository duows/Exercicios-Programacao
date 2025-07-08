#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back


using namespace std;

int32_t main() {

  freopen("test/input/10", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; cin >> N;

  
  vector<int> nums;
  for (int i = 0; i < N; i++) {
    int n; cin >> n;
    nums.pb(n);
  }


  vector<string> items;
  int sum = 0;
  for (int i = 0; i < 32; i++) {
    int cont = 0;
    string contagem = "";
    for (int j = 0; j < nums.size(); j++) {
      if ((1 << (31 - i)) & nums[j]) cont += 1;
    }

    if (cont != 0) {
      contagem += to_string(cont);
      contagem += "*2^";
      contagem += to_string(31-i);

      sum += (cont * pow(2, (31-i)));
      items.pb(contagem);
    }
  }

  cout << "chave: "; 
  for (int i = 0; i < items.size() - 1; i++) {
    cout << items[i] << "+";
  }

  cout << items[items.size() - 1] << "=" << sum << endl;

  

  return 0;
}