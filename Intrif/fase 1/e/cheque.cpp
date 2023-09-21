#include <iostream>
#include <queue>

using namespace std;

int main() {

    priority_queue<long long int> cheques;


    int n; cin >> n;

    for (int i = 0; i<n;i++) {
        long long int cheque; cin >> cheque;

        cheques.push(cheque);
    }

    long long int V; cin >> V;


    long long int res = 0;

    while (!cheques.empty()) {
        res += (V / cheques.top());
        V = (V % cheques.top());
        
        cheques.pop();
    }

    cout << res << endl;


    return 0;
}