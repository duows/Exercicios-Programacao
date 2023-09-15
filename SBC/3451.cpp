#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	
	
	string texto;
	
	int D; 
	
	cin >> texto >> D;
	
	if ((D < 1 || D > texto.length() || D > 200000 || texto.length() > 200000 || texto.length() < 1)) {
		return 0;
	}
	
	
	for (char &c : texto) {
		c = tolower(c);
	}
	
	string exec = texto.substr(0, D);
	int cont = 0;
	
	char caractere = exec.at(cont);
	
	int instrucoes = 1;
	
	int contString = 0;
	while (contString < texto.length()) {
		
		if (texto.at(contString) == caractere) {
			
			if (cont == exec.length()-1) {
				cont = 0;
			} else {
				cont++;	
			}
			
			caractere = exec.at(cont);
			contString++;
		} else {
			
			cont = 0;
			instrucoes++;
			
			
			if (contString < texto.length()) {
				exec = texto.substr(contString, D);
				caractere = exec.at(cont);
				contString += D;
			} else {
				break;
			}
		}
	}
	
	
	
	cout << instrucoes << endl;
	return 0;
}
