
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


// TIME LIMIT EXCEEDED

int main() {


    string value;

    vector<int> syracuse;

    unordered_map<int, int> cache;

    cache[4] = 2;

    while (value != "EOF") {
        cin >> value;

        if (value == "EOF") {
            break;
        }

        int N = stoi(value);

        if (N == 1) {
            syracuse.push_back(0);
        } else {

            if (cache[N] != 0) {
                syracuse.push_back(cache[N]);
            } else {
                int count = 0;
                int n = N;
                while (n != 1) {
                    if (n & 1) {
                        n = 3 * n + 1;
                    } else {
                        n = n / 2;
                    }
                    count++;
                }
                syracuse.push_back(count);
                cache[N] = count;
            }
        }
    }

    for (int i = 0; i < syracuse.size(); i++) {
        cout << syracuse[i] << endl;
    }   

    return 0;
}

