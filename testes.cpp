#include <bits/stdc++.h>

using namespace std;

// Comparador para ordenar as chaves em ordem decrescente
struct ComparadorInverso {
    bool operator()(const int &a, const int &b) const {
        return a > b; // Ordem inversa
    }
};

int main() {
    // Usando o comparador personalizado no map
    unordered_map<int, pair<int, int>> s;

    

    for (int i = 0; i < 5; i++) {
        s.insert(make_pair(i, make_pair(i, i)));
    }

    sort(s.begin(), s.end(), ComparadorInverso());

    s.erase(2);

    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->first << " " << it->second.first << " " << it->second.second << endl;
    }

    return 0;
}
