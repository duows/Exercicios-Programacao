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

int toDigit(char c)
{
    if (c >= '1' && c <= '9')
        return c - '0';
    if (c == 'X' || c == 'x')
        return 10;
    return 0;
}

int score(pair<string, string> &p, vector<int> &scores)
{
    int total_score = 0;
    int index = 0;
    string arremessos = p.s;

    for (int frame = 1; frame < 10; frame++)
    {
        if (arremessos[index] == 'X' || arremessos[index] == 'x')
        {
            total_score += 10 + toDigit(arremessos[index + 1]) + toDigit(arremessos[index + 2]);
            index++;
        }
        else
        {
            int throw1 = toDigit(arremessos[index]);
            int throw2 = toDigit(arremessos[index + 1]);
            if (throw1 + throw2 == 10)
            {
                total_score += 10 + toDigit(arremessos[index + 2]);
                index += 2;
            }
            else
            {
                total_score += throw1 + throw2;
                index += 2;
            }
        }
        scores.push_back(total_score);
    }

    int score_frame_10 = 0;
    for (size_t i = index; i < arremessos.length(); i++)
    {
        score_frame_10 += toDigit(arremessos[i]);
    }

    total_score += score_frame_10;
    scores.push_back(total_score);
    return total_score;
}

int main(){ _

    int x;
    cin >> x;

    vector<tuple<int, string, vector<int>>> resultados;

    for (int i = 0; i < x; i++)
    {
        pair<string, string> pessoa;
        cin >> pessoa.f >> pessoa.s;

        vector<int> scores_acumulados;
        int total = score(pessoa, scores_acumulados);

        resultados.emplace_back(-total, pessoa.f, scores_acumulados);
    }

    sort(resultados.begin(), resultados.end());

    for (const auto &res : resultados)
    {
        string nome = get<1>(res);
        int pontuacao_total = -get<0>(res);
        vector<int> pontuacoes_frame = get<2>(res);

        cout << nome << ": |";
        for (const auto &s : pontuacoes_frame)
        {
            cout << s << "|";
        }
        cout << " Total = " << pontuacao_total << endl;
    }

    return 0;
}