#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10000000;
vector<int> cache(MAX_N + 1, -1);

int collatz_iterations(int n) {
    if (n == 1) return 0;
    if (n <= MAX_N && cache[n] != -1) return cache[n];

    int result;
    if (n % 2 == 0) {
        result = 1 + collatz_iterations(n / 2);
    } else {
        if (n <= (MAX_N - 1) / 3) {
            result = 1 + collatz_iterations(3 * n + 1);
        } else {
            long long n_large = n;
            result = 1 + collatz_iterations(3 * n_large + 1);
        }
    }
    
    if (n <= MAX_N) cache[n] = result;
    return result;
}

int main() {
    vector<int> n_values;
    vector<int> i_values;

    int n;
    while (cin >> n) {
        n_values.push_back(n);
    }

    for (int j = 0; j < n_values.size(); ++j) {
        int n = n_values[j];
        int i = collatz_iterations(n);
        i_values.push_back(i);
    }

    for (int i = 0; i < i_values.size(); ++i) {
        cout << i_values[i] << endl;
    }

    return 0;
}
