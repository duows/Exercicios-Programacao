#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

long long mdc(long long a, long long b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

int main()
{
    long long m, n;
    cin >> m >> n;

    m + n - mdc(m, n) == 0 ? cout << m + n : cout << m + n - mdc(m, n);
    cout << endl;

    return 0;
}