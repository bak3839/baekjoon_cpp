#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s2.size() + 1, vector<int>(s1.size() + 1, 0));

    for (int i = 1; i <= s2.size(); i++) {
        for (int j = 1; j <= s1.size(); j++) {
            if (s1[j - 1] == s2[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(dp[i][j], ans);
            }
        }
    }

    cout << ans;
    return 0;
}