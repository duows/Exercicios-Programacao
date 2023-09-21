#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct equipe {
    string nome;
    vector<pair<int, pair<int, int>>> pontuacao;
};


struct ValueComparator {
    bool operator()(const pair<string, pair<int, pair<int, int>>>& a, const pair<string, pair<int, pair<int, int>>>& b) {
        return a.second > b.second;
    }
};

int main() {
    /*
        pair -> Pares ordenados.
        Ao comparar um pair, ele tenta comparar com o primeiro parâmetro, e posteriormente pelo segundo escrito.
        sort(alunos.begin(), alunos.end(), greater<pair<int, string>>()); -> Ordenar em ordem decrescente um vetor de pairs.
        sort(alunos.begin(), alunos.end()); -> Ordenar em ordem crescente um vetor de pairs.


        { pontos, { vitórias, gols } }


        { nomeTime, { pontos, { vitórias, saldo } } } -> map
    */

   
    map< string, pair< int, pair<int, int>> > times;

    int E; cin >> E;
    int n; cin >> n;

    for (int i = 0; i < n; i++) {

        string equipe1, equipe2, x;
        int gols1, gols2, pontos, vitorias, saldo;

        cin >> equipe1 >> gols1 >> x >> gols2 >> equipe2;
        
        saldo = gols1-gols2;

        if (times.find(equipe1) == times.end()) {
            
            if (gols1 > gols2) {
                pontos = 3;
                vitorias = 1;

            } else {

                vitorias = 0;

                if (gols1 == gols2) {
                    pontos = 1;
                } else {
                    pontos = 0;
                }

            }

            pair< int, pair<int, int>> par = {pontos, {vitorias, saldo}};

            times.insert(make_pair(equipe1, par));

        } else {

            if (gols1 > gols2) {
                pontos = 3;
                vitorias = 1;

            } else {

                vitorias = 0;

                if (gols1 == gols2) {
                    pontos = 1;
                } else {
                    pontos = 0;
                }

            }

            // <string, pair< int, pair< int, int > >>
            times[equipe1] = {times[equipe1].first+pontos, {times[equipe1].second.first+vitorias, times[equipe1].second.second+saldo}};
        }


        //Equipe2:
        if (times.find(equipe2) == times.end()) {
            
            saldo = -saldo;
            if (gols2 > gols1) {
                pontos = 3;
                vitorias = 1;
            } else {

                vitorias = 0;

                if (gols2 == gols1) {
                    pontos = 1;
                } else {
                    pontos = 0;
                }

            }

            pair< int, pair<int, int>> par = {pontos, {vitorias, saldo}};

            times.insert(make_pair(equipe2, par));

        } else {

            saldo = -saldo;
            if (gols2 > gols1) {
                pontos = 3;
                vitorias = 1;
            } else {

                vitorias = 0;

                if (gols1 == gols2) {
                    pontos = 1;
                } else {
                    pontos = 0;
                }

            }

            times[equipe2] = {times[equipe2].first+pontos, {times[equipe2].second.first+vitorias, times[equipe2].second.second+saldo}};

        }


    }


    vector< pair<string, pair<int, pair<int, int>> > > timesVector(times.begin(), times.end());

    sort(timesVector.begin(), timesVector.end(), ValueComparator());


    vector< pair< string, pair<int, pair<int, int>>> >::iterator itr;

    for (itr = timesVector.begin(); itr != timesVector.end(); itr++) {
        int pontos = (*itr).second.first;
        int vitorias = (*itr).second.second.first;
        int saldo = (*itr).second.second.second;

        cout << (*itr).first << " " << pontos << " " << vitorias << " " << saldo << endl;

    }

 
    return 0;
}