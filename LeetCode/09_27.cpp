#include <iostream>
#include <string>


#define INT long long int

using namespace std;


void escreverString(string *aux, string *repeticoes, string *decoded) {
    cout << *repeticoes << endl;
    
	int repeticoes2 = int stoi(*repeticoes);
	cout << "A2" << endl;
	while (repeticoes2 > 0) {
		repeticoes2--;
		*decoded = (*decoded) + (*aux);
	}
	
	*aux = "";
	*repeticoes = "";
}

int main()
{
	
	string s = "a2345678999999999999999";
	cout << "A1" << endl;
	
	int k = 1;
	
	string decoded = "", aux = "", repeticoes = "", res = "";
	
	bool comecouContagem = false;
	int cont = 0;
	for (char c : s) {
			
		if ( ((int) c >= 97 && (int) c <= 122) ) {
			//Caso seja um dígito
			
			if (comecouContagem) {
				comecouContagem = false;
				
				escreverString(&aux, &repeticoes, &decoded);
				
			}
			
			aux += c;
			
		} else {
			
			
			//Caso seja um número
			
			if (!comecouContagem) {
				
				comecouContagem = true;
				repeticoes = c;
				
			} else {
				repeticoes += c;
			}
			
			if (cont == s.length() - 2) {
				//Caso o dígito seja a penúltima letra
				escreverString(&aux, &repeticoes, &decoded);
				
			} else if (cont == s.length()-1) {
				string aux2 = decoded+aux;
				escreverString(&aux2, &repeticoes, &res);
			}
		}
		
		cont++;
			
	}
	
	char caractere = res[k-1];
	
	cout << caractere << endl;
	
	cout << res << endl;
    
    return 0;
}

