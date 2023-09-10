#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    bool sucesso = true;

    for (char c : s) {
        if (c != '0' && c != '1' && c != ' ') {
            sucesso = false;
            break;
        }
    }

    if (sucesso) {
        cout << "S" << endl;
    } else {
        cout << "F" << endl;
    }

    return 0;
}