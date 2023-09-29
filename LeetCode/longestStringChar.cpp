#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};

    sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });

    int tamanhoAtual = words[0].length();

    vector<string> words2;

    for (string w : words) {
        
        if (w.length() == tamanhoAtual) {

            words2.push_back(w);
            tamanhoAtual++;

        }

    }

    int res = 1;

    for (int i = 0; i < (words2.size()-1); i++) {
        //Percorrer as palavras candidatas
        string s1 = words2[i];
        string s2 = words2[i+1];

        reverse(s1.begin(), s1.end());

        for (char c : s2) {
            if (s1.back() == c) {
                s1.pop_back();
            }
        }

        if (s1.empty()) {
            res++;
        }

    }

    cout << res << endl;

    return 0;
}