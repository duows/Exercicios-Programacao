#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream> // Add this line

using namespace std;

int main() {

    int n=0;
    int player[3];

    for (int i = 0; i < 3; i++) {
        player[i] = 0;
    }

    cin >> n;
    cin.ignore();

    vector<int> v;
    string str;

    getline(cin, str);

    stringstream ss(str);
    int val=0;
    int rodada=0;
    while (ss >> val) {
        v.push_back(val);
    }

    int i = n - 1;

    for (int val : v) {
        if (val == 0) {
            i++;
            if (i > 2) {
                i = 0;
            }
        } else {
            if (val == -1) {
                break;
            }
            switch (val) {
                case 1:
                    player[i] += 5;
                    break;
                case 2:
                    player[i] += 10;
                    break;
                case 3:
                    player[i] += 15;
                    break;
                case 4:
                    player[i] += 20;
                    break;
                case 5:
                    player[i] += 50;
                    break;
            }
        }
    }

    cout << "RODADA " << rodada << endl;

    if (player[0] > player[1]) {
        if (player[0] > player[2]) {
            cout << "Ganhador com " << player[0] << " pontos" << endl;
            cout << "Jogador 1" << endl;
        } else {
            cout << "Ganhador com " << player[2] << " pontos" << endl;
            cout << "Jogador 3" << endl;
        }
    } else {
        if (player[1] > player[2]) {
            cout << "Ganhador com " << player[1] << " pontos" << endl;
            cout << "Jogador 2" << endl;
        } else {
            cout << "Ganhador com " << player[2] << " pontos" << endl;
            cout << "Jogador 3" << endl;
        }
    }


    return 0;
}
