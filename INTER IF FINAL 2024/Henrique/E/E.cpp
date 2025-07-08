#include <bits/stdc++.h>

using namespace std;

/*macro para código mais rapido e para \n*/
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); // n usar printf junto com cout
//^comentar _ para degubar código
#define endl '\n'

/* macro aleatorias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

#define printv(a)                               \
    do                                          \
    {                                           \
        for (size_t i = 0; i < (a).size(); ++i) \
        {                                       \
            cout << (a)[i];                     \
            if (i < (a).size() - 1)             \
                cout << " ";                    \
        }                                       \
        cout << endl;                           \
    } while (0)

#define printv2(a)             \
    do                         \
    {                          \
        for (auto x : (a))     \
            cout << x << endl; \
    } while (0)

#define print_matrix(m, l, c)             \
    do                                    \
    {                                     \
        for (int i = 0; i < (l); ++i)     \
        {                                 \
            for (int j = 0; j < (c); ++j) \
            {                             \
                cout << (m)[i][j] << " "; \
            }                             \
            cout << endl;                 \
        }                                 \
    } while (0)

/* macro para trabalhar com pair*/
#define f first
#define s second

/* funcao para debugging*/
#define dgb(x) cout << #x << " = " << x << endl;

/* define long long como ll */
typedef long long ll;

/* define constantes infinitas */
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;

/* criar arquivo baseado no template
cp ~/templates/template.cpp ~/projetos/meu_novo_codigo.cpp

compilar
g++ -std=c++17 -o meu_novo_codigo ~/projetos/meu_novo_codigo.cpp
./meu_novo_codigo

criar pastas
for i in {A..Z}; do mkdir -p "$i"; cp ~/templates/template.cpp "$i/$i.cpp"; done
*/

string decodificarLinha(const string& palavra) {
    string word = "";

    for (int i = 0; i < palavra.length(); ++i) {
        char c = palavra[i];

        if (isalpha(c)) {
            word += c;
        } else if (isdigit(c)) {
            string num;
            if (c == '1') {
                num = palavra.substr(i, 3);
                i += 2;
            } else {
                num = palavra.substr(i, 2);
                i += 1;
            }
            word += static_cast<char>(stoi(num));
        } else {
            word += c;
        }
    }

    return word;
}

int main() { _

    int n;
    cin >> n;

    string dummy;
    getline(cin, dummy);

    for (int i = 0; i < n; ++i) {
        string linha;
        getline(cin, linha);
        
        cout << decodificarLinha(linha) << '\n';
    }

    return 0;
}
