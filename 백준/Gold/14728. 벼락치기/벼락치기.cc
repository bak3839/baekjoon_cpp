#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, T, time, score;
    cin >> N >> T;

    vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));

    for (int i = 1; i <= N; i++) {
        cin >> time >> score;

        for (int j = 1; j <= T; j++) {
            if (j - time < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time] + score);
        }
    }

    cout << dp[N][T];
    return 0;
}