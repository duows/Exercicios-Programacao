#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

bool isMultiple(string &s, int n) {
    long long int remainder = 0;
    for (char c : s) {
        remainder = (remainder * 10 + (c - '0')) % n;
    }
    return remainder == 0;
}

int main() { _
    string s; cin >> s;
    int n; cin >> n;

    vector<int> missing;
    int pos = 0;
    
    // Identificar as posições dos '?'
    for (char &c : s) {
        if (c == '?') {
            missing.push_back(pos);
        }
        pos++;
    }

    // Definir o número máximo de combinações possíveis
    int totalCombinations = pow(10, missing.size());
    bool found = false;

    // Testar todas as combinações possíveis
    for (int i = 0; i < totalCombinations; i++) {
        string replace = to_string(i);
        
        while (replace.size() < missing.size()) {
            replace = '0' + replace;
        }

        // Substituir os '?' pelas combinações geradas
        for (int j = 0; j < missing.size(); j++) {
            if (missing[j] == 0 && replace[j] == '0') {
                replace[j] = '1';  // Garantir que o número não comece com '0'
            }
            s[missing[j]] = replace[j];
        }

        // Verificar se é múltiplo
        if (isMultiple(s, n)) {
            found = true;
            cout << s << endl;
            break;
        }
    }

    if (!found) {
        cout << '*' << endl;
    }

    return 0;
}
