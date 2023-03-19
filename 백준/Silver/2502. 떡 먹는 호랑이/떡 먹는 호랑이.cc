#include <iostream>

using namespace std;

int dp[2][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int D, K;
    cin >> D >> K;

    dp[0][1] = 1;
    dp[1][1] = 0;
    dp[0][2] = 0;
    dp[1][2] = 1;

    for (int i = 3; i <= D; i++) {
        dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
        dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
    }

    int rest = 0, sum = 0, i;

    for (i = 1; i <= K; i++) {       
        rest = K - (dp[0][D] * i);
        if (rest % dp[1][D] == 0) break;
    }

    cout << i << "\n" << rest / dp[1][D];
    
    return 0;
}