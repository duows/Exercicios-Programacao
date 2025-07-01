#include <bits/stdc++.h>

using namespace std;

/*macro para código mais rapido e para \n*/
#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
//^comentar _ para degubar código
#define endl '\n'


/* macro aleatorias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

#define printv(a) do {                             \
    for (size_t i = 0; i < (a).size(); ++i) {      \
        cout << (a)[i];                            \
        if (i < (a).size() - 1)                    \
            cout << " ";                           \
    }                                              \
    cout << endl;                                  \
} while(0)

#define printv2(a) do {                            \
    for (auto x : (a))                             \
        cout << x << endl;                         \
} while(0)

#define print_matrix(m, l, c) do {                 \
    for (int i = 0; i < (l); ++i) {                \
        for (int j = 0; j < (c); ++j) {            \
            cout << (m)[i][j] << " ";              \
        }                                          \
        cout << endl;                              \
    }                                              \
} while(0)


/* macro para trabalhar com pair*/
#define f first
#define s second

/* funcao para debugging*/
#define dgb(x) cout << #x << " = " << x << endl;

/* define long long como ll */
typedef long long ll;


/* define constantes infinitas */
//const int INF = 0x3f3f3f3f;
//const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main() { _
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        string s, c;
        cin >> s >> c;

        if (s.length() != c.length()) continue;

        bool ignorar = false;
        for (char x : s) {
            if (!islower(x)) {
                ignorar = true;
                break;
            }
        }
        for (char x : c) {
            if (!islower(x)) {
                ignorar = true;
                break;
            }
        }

        if (ignorar) continue;

        string ans = "";
        bool horario = true;

        for (int i = 0; i < s.length(); i++) {
            int letra = s[i] - 'a';
            int deslocamento = (c[i] - 'a') + 1;
            int nova_pos;

            if (n == 1) { // Criptografar
                if (horario) {
                    nova_pos = (letra + deslocamento) % 26;
                } else {
                    nova_pos = (letra - deslocamento + 26) % 26;
                }
            } else if (n == 2) { // Descriptografar
                if (horario) {
                    nova_pos = (letra - deslocamento + 26) % 26;
                } else {
                    nova_pos = (letra + deslocamento) % 26;
                }
            }

            ans += (char)(nova_pos + 'a');
            horario = !horario;
        }

        cout << ans << endl;
    }

    return 0;
}
