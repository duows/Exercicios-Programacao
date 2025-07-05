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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool dentro(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() { _
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matriz(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> matriz[i][j];

    int curvas_perigosas = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matriz[i][j] != 1) continue;

            // Checar pares ortogonais de água que formam cotovelos
            bool cima = dentro(i - 1, j, N, M) && matriz[i - 1][j] == 2;
            bool direita = dentro(i, j + 1, N, M) && matriz[i][j + 1] == 2;
            bool baixo = dentro(i + 1, j, N, M) && matriz[i + 1][j] == 2;
            bool esquerda = dentro(i, j - 1, N, M) && matriz[i][j - 1] == 2;

            if ((cima && direita) || (direita && baixo) ||
                (baixo && esquerda) || (esquerda && cima)) {
                curvas_perigosas++;
            }
        }
    }

    cout << curvas_perigosas << endl;

    return 0;
}
