#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> dp(3, vector<int>(N + 1));
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % 9901;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % 9901;
        dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % 9901;
    }

    cout << (dp[0][N] + dp[1][N] + dp[2][N]) % 9901;
    return 0;
}