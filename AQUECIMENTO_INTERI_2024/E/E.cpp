#include <iostream>
#include <unordered_map>

using namespace std;

// Declaração da função f
int f(int x, unordered_map<int, int>& memo);

// Implementação da função f
int f(int x, unordered_map<int, int>& memo) {
    if (x >= 10000000) {
        return x - 3;
    }
    if (memo.find(x) != memo.end()) {
        return memo[x];
    }
    memo[x] = f(f(f(x + 13, memo), memo), memo);
    return memo[x];
}

int main() {
    int x;

    cin >> x;

    unordered_map<int, int> memo;
    int resultado = f(x, memo);
    cout << resultado << endl;

    return 0;
}
