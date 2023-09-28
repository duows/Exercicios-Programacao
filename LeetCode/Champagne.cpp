#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	
	int poured = 2;
	
    vector<double> linhaAtual(1, poured);

    int query_row = 1;
    int query_glass = 1;

    cout << "Poured: " << poured << endl;
    
    for (int i = 0; i < query_row; i++) {
        
        //Percorrendo as linhas
        vector<double> prox(linhaAtual.size() + 1);

        for (int j = 0; j < linhaAtual.size(); j++) {

            //Percorrendo a linha atual
            if (linhaAtual[j] >= 1) {

                prox[j] = (linhaAtual[j]-1.0)/2.0;
                prox[j+1] = (linhaAtual[j]-1.0)/2.0;

                linhaAtual[j] = 1;
            } 

        }

        linhaAtual = prox;
    }
    
    if (linhaAtual[query_glass] > 1) {
	linhaAtual[query_glass] = 1;
    }


    cout << linhaAtual[query_glass] << endl;
	
	
	
	
    return 0;
}
