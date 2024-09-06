#include <bits/stdc++.h>

using namespace std;

/*macro para código mais rapido e para \n*/
#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
//^comentar _ para degubar código
#define endl '\n'


/* macro aleatorias */
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>


/* macro para trabalhar com pair*/
#define f first
#define s second


/* funcao para debugging*/
#define dgb(x) cout << #x << " = " << x << endl;

#define print(a) for(auto x : a) cout << x << " "; cout << endl

/* define long long como ll */
typedef long long ll;


/* define constantes infinitas */
//const int INF = 0x3f3f3f3f;
//const ll LINF = 0x3f3f3f3f3f3f3f3fll;


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
	vi v(91, 0);
	
	for (int i=1; i <= n; i++) {
		int aux; cin >> aux;
		v[aux] = 1;
		
	}
	
	
	int tempo=0, limite=0;
	for (int i=1; i <= 90; i++) {
		
		
		if (limite >= 15) break;
		else {
			if (v[i] == 1) {
				limite = 0;
			} else {
				limite += 1;
			}
		}
		
		tempo++;
	}

	cout << tempo << endl;
	
	return 0;
}
