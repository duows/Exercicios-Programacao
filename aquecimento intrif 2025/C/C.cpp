#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main() { _

  unordered_map<int, int> frequencia = { {6, 0}, {5, 0}, {4, 0} };
  unordered_map<int, int> numerosLoteria;
  vector<int> loteria(6, 0);
  for (int i = 0; i < loteria.size(); i++) {
    cin >> loteria[i];
    numerosLoteria[loteria[i]] = 1;
  }

  int finaliza =  1;
  while(true) {

    vector<int> aposta(6, 0);

    int acertos = 0;
    for (int i = 0; i < aposta.size(); i++) {
      cin >> aposta[i];

      if (aposta[i] != 0) {
        finaliza = 0;
      }

      if (numerosLoteria[aposta[i]] == 1) {
        acertos++;
      }
    }

    if (finaliza == 1) {
      break;
    }

    frequencia[acertos]++;
    finaliza = 1;

  }

  cout << "6 " << frequencia[6] << endl;
  cout << "5 " << frequencia[5] << endl;
  cout << "4 " << frequencia[4] << endl;
  return 0;
}
