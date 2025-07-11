#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
    int C, N;
    vector<int> P;

    cin >> C;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        P.push_back(x);
    }

    vector<int> massa_maxima(C + 1, 0);

    for (int i = 0; i < N; i++)
    {
        int pAtual = P[i];

        for (int j = C; j >= pAtual; j--)
        {
            massa_maxima[j] = max(massa_maxima[j], pAtual + massa_maxima[j - pAtual]);
        }
    }

    cout << massa_maxima[C] << endl;

    return 0;
}