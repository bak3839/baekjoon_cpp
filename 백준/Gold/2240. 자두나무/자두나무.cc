#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, W, tree, ans = 0;
    cin >> T >> W;

    dp.resize(W + 2, vector<int>(T + 1, 0));

    for (int i = 1;i <= T;i++) {
        cin >> tree;

        if (tree == 1) {
            for (int j = 1;j <= W + 1;j++) {
                if (j % 2 != 0) dp[j][i] = max(dp[j][i - 1] + 1, dp[j - 1][i - 1] + 1);
                else dp[j][i] = dp[j][i - 1];
                ans = max(dp[j][i], ans);
            }
        }

        else {
            for (int j = 1;j <= W + 1;j++) {
                if (j % 2 == 0) dp[j][i] = max(dp[j][i - 1] + 1, dp[j - 1][i - 1] + 1);
                else dp[j][i] = dp[j][i - 1];
                ans = max(dp[j][i], ans);
            }
        }
    }

    cout << ans;
    return 0;
}