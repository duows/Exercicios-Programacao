#include <iostream>
#include <vector>

using namespace std;


struct Ficha {
    int x;
    int y;
};

struct Jogador {
    int a;
    int b;
    vector<int> fichas;
};

int main() {

    ios::sync_with_stdio(0); cin.tie(0);


    int T; cin >> T;

    if (T < 1 || T > 100000) {
        return 0;
    }   

    Ficha fichas[T];
    int fichasUtilizadas[T];

    for (int i = 0; i<T;i++) {
        fichasUtilizadas[i] = 0;
    }

    for (int i = 0; i < T; i++) {
        cin >> fichas[i].x;
        cin >> fichas[i].y;

        if (fichas[i].x < (-1000000000) || fichas[i].x > 1000000000 || fichas[i].y < (-1000000000) || fichas[i].y > 1000000000) {
            return 0;
        }
    }

    int P; cin >> P;

    if (P < 1 || P > 100000) {
        return 0;
    }

    Jogador jogadores[P];

    for (int i= 0; i<P;i++) {

        cin >> jogadores[i].a;
        cin >> jogadores[i].b;

        if (jogadores[i].a < (-1000000000) || jogadores[i].a > 1000000000 || jogadores[i].b < (-1000000000) || jogadores[i].b > 1000000000) {
            return 0;
        }

    }

    int total=0;
    for (int i = 0; i < P;i++) { //Jogadores

        if (total == T) {
            break;    
        }
        
        for (int j = 0; j < T; j++) { //Fichas
            int a = jogadores[i].a;
            int b = jogadores[i].b;
            
            int y = (a*fichas[j].x) + b;

            if (fichasUtilizadas[j] == 0) {
                
                if ( (a == 0 && b == 0 && fichas[j].y < 0 && fichas[j].x == 0) || (fichas[j].y < y) ) {
                    jogadores[i].fichas.push_back(j);
                    fichasUtilizadas[j] = 1;
                    total += 1;
                }

            }
        }
    }

    for (int i = 0; i < P; i++) {

        cout << jogadores[i].fichas.size();

        if (jogadores[i].fichas.size() > 0) {
            
            for (int itr : jogadores[i].fichas) {

                if (itr == *jogadores[i].fichas.begin()) {
                    cout << " ";
                }

                cout << itr+1;
                
                if (itr != *jogadores[i].fichas.end()) {
                    cout << " ";
                }

            }
        }

        cout << endl;
    }



    return 0;
}