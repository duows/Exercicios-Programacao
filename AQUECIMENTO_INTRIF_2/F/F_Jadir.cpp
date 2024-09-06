#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
#define endl '\n'

#define ull unsigned long long int
/* define constantes infinitas
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
*/

bool isMultiple(string s, int n) {
    long long int remainder = 0;
    for (char c : s) {
        remainder = (remainder * 10 + c - '0') % n;
    }
    return remainder == 0;
}

string incrementNumber(string number) {
    int carry = 1;
    for (int i = number.size() - 1; i >= 0 && carry; --i) {
        if (number[i] == '9') {
            number[i] = '0';
        } else {
            number[i]++;
            carry = 0;
        }
    }
    if (carry) {
        number = '1' + number;
    }
    return number;
}

int main() { _

    string s; cin >> s;
    int n; cin >> n;

    vector<int> missing;
    int pos = 0;
    for (char &c : s) {
        if (pos == 0 && c == '?') {c='1'; missing.push_back(pos); pos++;}
        else {
            if (c == '?') {
                missing.push_back(pos);
            }
            pos++;
        }
    }

    string maximalValue = "";
    string actualValue = "";
    for (int i = 0; i < missing.size(); i++) {
        maximalValue += '9';
        if (missing[i] != 0) {
            actualValue += '0';
        } else {
            actualValue += '1';
        } 
    }
    
    int existe = 0;
    string s2 = s;
    while (actualValue != maximalValue) {
        
        for (int i = 0; i < missing.size(); i++) {
            s2[missing[i]] = actualValue[i];
        }

        if (isMultiple(s2, n)) {
            existe = 1;
            break;
        }

        actualValue = incrementNumber(actualValue);
        s2=s;
    }

    if (existe) cout << s2 << endl;
    else cout << '*' << endl;
	return 0;
}
