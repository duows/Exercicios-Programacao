#include <bits/stdc++.h>

using namespace std;

/*macro para c�digo mais rapido e para \n*/
#define _ ios_base::sync_with_stdio(0);cin.tie(0); //n usar printf junto com cout
//^comentar _ para degubar c�digo
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

	int d, m, a; cin >> d >> m >> a;
	int dia=0;
	
	dia = (((2015 - a) * 360) + ((6 - m) * 30) + (10 - d)) * 2;
	
	cout << dia << endl;

	return 0;
}
