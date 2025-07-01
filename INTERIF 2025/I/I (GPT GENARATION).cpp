#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); 

#define endl '\n'


using namespace std;




int main() { _



    vector<char> alfabeto = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    while (true) {

        int n; cin >> n;

        //finaliza programa
        if (n == 0) {
            break;
        }
        string s; cin >> s;

        string c; cin >> c;

        if (s.length() != c.length()) continue;

        int ignorar = 0;
        for (char &x : s) {
            if (!islower(x)) {
                ignorar = 1;
                break;
            }
            x = tolower(x);
        }

        if (ignorar) continue;

        for (char &x : c) {
            if (!islower(x)) {
                ignorar = 1;
                break;
            }
            x = tolower(x);
        }

        if (ignorar) continue;

        //criptografar palavra
        if (n == 1) {
            string ans = "";
            bool h = 0;
            for (int i = 0; i < s.length(); i++) {
                char v = s[i];

                char v2 = c[i];

                if (h == 0) {
                    h = 1;
                    int pos = (v -'a') - (v2 - 'a') - 1;

                    if (pos < 0) {
                        pos = alfabeto.size() + pos;
                    } 

                    ans += alfabeto[pos];


                } else {
                    int pos = ((v - 'a') + (v2 - 'a') + 1) % alfabeto.size();

                    ans += alfabeto[pos];
                    h = 0;
                }

            }

            cout << ans << endl;

        }

        //descriptografar palavra
        if (n == 2) {
            string ans = "";
            bool h = 1;
            for (int i = 0; i < s.length(); i++) {
                char v = s[i];

                char v2 = c[i];

                if (h == 0) {
                    h = 1;
                    int pos = (v -'a') - (v2 - 'a') - 1;

                    if (pos < 0) {
                        pos = alfabeto.size() + pos;
                    } 

                    ans += alfabeto[pos];


                } else {
                    int pos = ((v - 'a') + (v2 - 'a') + 1) % alfabeto.size();

                    ans += alfabeto[pos];
                    h = 0;
                }

            }

            cout << ans << endl;
        }

    }


    return 0;
}