#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, t, ans = 0;

    cin >> N;
    vector<int> c(N + 1);
    vector<vector<int>> dp(4, vector<int>(N + 1, 0));
    c[0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    cin >> t;

    for (int i = 1; i <= 3; i++) {
        for (int j = i * t; j <= N; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - t] + c[j] - c[j - t]);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}