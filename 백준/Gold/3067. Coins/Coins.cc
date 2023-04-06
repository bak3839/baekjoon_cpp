#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, N, res;
    vector<int> coin;
    vector<int> dp;
    cin >> T;

    while (T--) {
        cin >> N;
        coin.resize(N);

        for (int i = 0; i < N; i++) cin >> coin[i];
        cin >> res;

        dp.resize(10001, 0);

        for (int i = 0; i < coin.size(); i++) {
            dp[coin[i]] += 1;

            for (int j = coin[i] + 1; j <= res; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[res] << "\n";
        dp.clear();
        coin.clear();
    }

    return 0;
}