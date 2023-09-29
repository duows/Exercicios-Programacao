#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	
	int poured = 100000009;
	
    vector<double> linhaAtual(1, poured);

    int query_row = 33;
    int query_glass = 17;

    cout << "Poured: " << poured << endl;
    
    for (int i = 0; i < query_row; i++) {
        
        //Percorrendo as linhas
        vector<double> prox(linhaAtual.size() + 1);

        for (int j = 0; j < linhaAtual.size(); j++) {

            //Percorrendo a linha atual
            if (linhaAtual[j] >= 1) {

                prox[j]  = (linhaAtual[j]-1.0)/2.0;
                prox[j+1] = (linhaAtual[j]-1.0)/2.0;
                linhaAtual[j] = 1;
            } 

        }

        linhaAtual = prox;
    }


    cout << linhaAtual[query_glass] << endl;
	
	
	
	
    return 0;
}