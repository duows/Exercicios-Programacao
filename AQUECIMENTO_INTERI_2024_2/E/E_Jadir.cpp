#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
#define endl '\n'

/* define constantes infinitas
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
*/

int main() { _

    int n; cin >> n;

    vector<int> multiplicadores = {20, 19, 17, 14, 10, 5};


    vector<string> resps;
    for (int i = 0; i < n; i++) {
        string cdn; cin >> cdn;


        if ((cdn[0] == cdn[1] && cdn[1] == cdn[2] && cdn[2] == cdn[4] && cdn[4] == cdn[5] && cdn[5] == cdn[6]) || (cdn.size() != 9)) {
            resps.push_back("CDN INVALIDO!");
            continue;
        }


        int pos = 0;
        int soma = 0;
        for (int j = 0; j < 7; j++) {
            if (cdn[j] != '.') {
                soma += (cdn[j] - '0') * multiplicadores[pos];
                pos++;
            } 
        }

        int resto = soma % 11;

        if (resto > 1) {
            resto = 11-resto;
        } else {
            resto = 0;
        }

        if (resto == (cdn[8] - '0')) {
            resps.push_back("CDN VALIDO!");
        } else {
            resps.push_back("CDN INVALIDO!");
        }
    }


    for (string s : resps) {
        cout << s << endl;
    }

    cout << endl;
	return 0;
}
