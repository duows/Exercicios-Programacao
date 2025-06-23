#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main() { _

  vector<int> respostas;
    int N;
    do {
         cin >> N;
        
        if (N == 0) {
            break;
        }
        
        int maxNum = INT_MIN, posMax = 1;
        for (int i = 1; i <= N; i++) {
            int L; cin >> L;
            
            if (L > maxNum) {
                maxNum = L;
                posMax = i;
            }
        }
        
        respostas.push_back(posMax);
    } while (N != 0);
    
    for (int i = 0; i < respostas.size(); i++) {
        cout << respostas[i] << endl;
    }
  return 0;
}
