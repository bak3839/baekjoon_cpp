#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, coin;

	cin >> n >> k;
	vector<int> dp(k + 1, k + 1);

	for (int i = 0;i < n;i++) {
		cin >> coin;
		dp[coin] = 1;
		for (int j = coin + 1;j <= k;j++) {
			dp[j] = min(dp[j], dp[coin] + dp[j - coin]);
		}
	}

	if (dp[k] == k + 1) cout << -1;
	else cout << dp[k];
	return 0;
}