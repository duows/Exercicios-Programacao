#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& s) {
    vector<int> charCount(256, 0);

    for (char c : s) {
        charCount[c]++;
    }

    int oddCount = 0;
    for (int count : charCount) {
        if (count % 2 != 0) {
            oddCount++;
        }
        if (oddCount > 1) {
            return false;
        }
    }

    return true;
}

int main() {
    string str;
    cin >> str;

    if (isPalindrome(str)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
