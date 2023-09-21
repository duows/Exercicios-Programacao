#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    int base[8];

    for (int i = 0; i<8;i++) {
        cin >> base[i];
        if (base[i] < 1 || base[i] > 3) {
            return 0;
        }
    }


    float soma = 0;
    int n; cin >> n;
    vector<float> perc;


    for (int i = 0; i < n;i++) { 

        for (int j = 0; j < 8; j++) {
            int val; cin >> val;

            if (val == base[j]) {
                soma++;
            }

        }

        float res = (soma/8.0f)*100.0f;

        perc.push_back(res);
        soma = 0;
    }

    int m; cin >> m;
    
    vector<float> percAnalise;

    if (m < 1 || m > 100) {
        return 0;
    }

    for (int i = 0; i< m; i++) {
        int val;
        cin >> val;

        if (val < 1 || val > 100) {
            return 0;
        }

        percAnalise.push_back(val);

    }

    vector<float> resultados;
    float val = 0;

    int cont = 0;
    for (int i = 0; i < m;i++) {
        
        for (int j = 0; j < n; j++) {

            if (perc.at(j) >= percAnalise.at(i)) {
                val++;
            }

        }

        resultados.push_back((val/ (float) n)*100.0f);
        cont++;
        val=0;
        
    }


    for (float res : resultados) {
        printf("%.2f\n", res);
    }



    return 0;
}
