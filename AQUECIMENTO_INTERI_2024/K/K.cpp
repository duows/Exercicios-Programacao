#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> prices(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    vector<double> dp(N + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j] + prices[j - 1]);
        }
    }

    printf("%.2f\n", dp[N]);

    return 0;
}
