#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, res = 0, t, p;
    cin >> N;

    vector<pair<int, int>> v(N + 1);
    vector<int> dp(N + 2, 0);

    for (int i = 1; i <= N; i++) cin >> v[i].first >> v[i].second;

    for (int i = 1; i <= N; i++) {
        t = v[i].first;
        p = v[i].second;

        if (i + t <= N + 1) {
            for (int j = i + t; j <= N + 1; j++) {
                dp[j] = max(dp[i] + p, dp[j]);
            }          
        }
    }

    cout << dp[N + 1];
    return 0;
}