#include <iostream>
#include <string>

using namespace std;

int main() {
    string nStr;
    int sumOdd = 0, sumEven = 0;

    cin >> nStr;

    for (char c : nStr) {
        if (isdigit(c)) {
            int digit = c - '0';

            if (digit % 2 == 0) {
                sumEven += digit;
            } else {
                sumOdd += digit;
            }
        }
    }

    cout << (sumEven % 3 == 0 ? "S" : "N") << endl;
    cout << (sumOdd % 3 == 0 ? "S" : "N") << endl;

    return 0;
}
