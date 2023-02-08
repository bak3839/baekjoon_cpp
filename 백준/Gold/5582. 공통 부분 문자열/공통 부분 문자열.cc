#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s2.size(), vector<int>(s1.size()));

    for (int i = 0; i < s2.size(); i++) {
        for (int j = 0; j < s1.size(); j++) {
            if (s1[j] == s2[i]) {
                if (i > 0 && j > 0) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = 1;
                ans = max(dp[i][j], ans);
            }

            else dp[i][j] = 0;
        }
    }

    cout << ans;
    return 0;
}