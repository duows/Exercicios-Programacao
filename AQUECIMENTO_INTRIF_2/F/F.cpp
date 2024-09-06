#include <bits/stdc++.h>

using namespace std;

/*macro para código mais rápido*/
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define endl '\n'

#define int long long

/* define constantes infinitas */
typedef long long ll;

int charToInt(char c) {
    return c - '0';
}

int32_t main() { _
    
    int n; 
    cin >> n;
    
    vector<string> res;
    
    for (int i = 0; i < n; i++) {
        string doc; 
        cin >> doc;
        // NNN.NNN-D
        if (doc.size() != 9 || doc[3] != '.' || doc[7] != '-' ) {
            res.push_back("CDN INVALIDO!");
            continue;
        }

        int a = charToInt(doc[0]);
        int b = charToInt(doc[1]);
        int c = charToInt(doc[2]);
        int d = charToInt(doc[4]);
        int e = charToInt(doc[5]);
        int f = charToInt(doc[6]);
        int g_or = charToInt(doc[8]);
        
        if (a == b && b == c && c == d && d == e && e == f) {
            res.push_back("CDN INVALIDO!");
            continue;
        }

        int sum = 20 * a + 19 * b + 17 * c + 14 * d + 10 * e + 5 * f;
        int resto = sum % 11;
        int g=0;

        if (resto == 0 || resto == 1) {
            g = 0;
        } else {
        	if (resto == 2 || resto == 3 || resto == 4 || resto == 5 || resto == 6 || resto == 7 || resto == 8 || resto == 9 || resto == 10) g = 11 - resto;
        	else g = -1;
        }

        if (g == g_or && g != -1) {
            res.push_back("CDN VALIDO!");
        } else {
            res.push_back("CDN INVALIDO!");
        }
    }
    
    for (const string& resultado : res) {
        cout << resultado << endl;
    }

    return 0;
}
