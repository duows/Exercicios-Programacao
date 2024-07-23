#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

unsigned long long calculaTermo(unsigned long long N, unordered_map<unsigned long long, unsigned long long>& memo) {
    
    if (memo.find(N) != memo.end()) {
        return memo[N];
    }

    if (N <= 3) {
        return 1;
    }

    unsigned long long resultado = calculaTermo(N - 2, memo) + calculaTermo(N - 3, memo);
    memo[N] = resultado;
    return resultado;
}

int main() {
    unordered_map<unsigned long long, unsigned long long> memo;
    vector<unsigned long long> termos;
    string value;

    while (getline(cin, value)) {
        if (value == "EOF") {
            break;
        }

        unsigned long long N = stoull(value); 

        termos.push_back(calculaTermo(N, memo));
    }

    for (const auto& termo : termos) {
        cout << termo << endl;
    }

    return 0;
}
