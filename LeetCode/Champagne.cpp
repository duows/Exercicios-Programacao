#include <iostream>
#include <vector>

using namespace std;



int main() {
	
	
	vector< vector<double> > tacas;
	
	vector<double> vec1 = {1};
	tacas.push_back(vec1);
	
	int poured = 2;
	
	
	int limit = 2;
	
	for (int i = 0; i < 4;i++) {
		//Inserindo 4 linhas
		
		vector<double> vec2;
		
		for (int j = 0; j < limit; j++) {
			vec2.push_back(0);
		}
		
		tacas.push_back(vec2);
		
		limit++;
	}
	
	
	int linha = 1;
	
	for (vector<double> vec : tacas) {
		for (double val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	
	
	
	
	
    return 0;
}
