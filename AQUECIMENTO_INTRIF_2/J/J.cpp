#include <bits/stdc++.h>

using namespace std;

/* macro para código mais rapido e para \n*/
#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
//^comentar _ para degubar código
#define endl '\n'


/* macro aleatorias*/
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>


/* macro para trabalhar com pair*/
#define f first
#define s second


/* funcao para debugging*/
#define dgb(x) cout << #x << " = " << x << endl;


/* define long long como ll*/
typedef long long ll;

#define print(a) for(auto x : a) cout << x << endl

/* define constantes infinitas
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
*/

/* criar arquivo baseado no template
cp ~/templates/template.cpp ~/projetos/meu_novo_codigo.cpp

compilar
g++ -std=c++17 -o meu_novo_codigo ~/projetos/meu_novo_codigo.cpp
./meu_novo_codigo

criar pastas
for i in {A..Z}; do mkdir "$i"; done

*/

int main() { _

	vector<string> res;

	while (true) {
		int aux, aux2; cin >> aux >> aux2;
		
		if (aux == 0 and aux2 == 0) {
			break;
		}
		
		if (aux == aux2) {
			res.pb("IGUAL");
		}
		else if (aux == 4 or aux2 == 3) {
			res.pb("MENOR");
		} 
		else if (aux2 == 2 && aux != 3) {
			res.pb("MENOR");
		}
		else if (aux2 == 1 && aux != 3 && aux != 2) {
			res.pb("MENOR");
		}
		else if (aux2 == 4 or aux == 3) {
			res.pb("MAIOR");
		} 
		else if (aux == 2 && aux2 != 3) {
			res.pb("MAIOR");
		}
		else if (aux == 1 && aux2 != 3 && aux2 != 2) {
			res.pb("MAIOR");
		}
		else if (aux2 > aux) {
			res.pb("MENOR");
		}
		else {
			res.pb("MAIOR");
		}
	}

	print(res);
	
	return 0;
}
