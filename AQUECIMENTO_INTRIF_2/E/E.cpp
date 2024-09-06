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

	int n; cin >> n;
	
	vector<string> cdn, res;
	
	for (int i=0; i < n; i++) {
		string aux; cin >> aux;
		cdn.pb(aux);
	}

	for (auto c : cdn) {
		int soma=0;
		int g=0;
		soma = ((c[0] - '0') * 20) + ((c[1] - '0') * 19) + ((c[2] - '0') * 17) + ((c[4] - '0') * 14) + ((c[5] - '0') * 10) + ((c[6] - '0') * 5);
		
		if ((soma % 11) == 0 or (soma % 11) == 1) {
			g = 0; 
		} else {
			g = 11 -(soma % 11); 
		}

		if (g == (c[8] - '0') ) {
			res.pb("CDN VALIDO!");
		} else {
			res.pb("CDN INVALIDO!");
		}
	}

	print(res);

	return 0;
}
