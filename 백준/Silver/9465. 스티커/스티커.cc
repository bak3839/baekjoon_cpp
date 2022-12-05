#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, T;
	vector<vector<int>> s(2);
	vector<vector<int>> dp(2);

	cin >> T;
	while (T--) {
		cin >> n;
		s[0].resize(n); s[1].resize(n);
		dp[0].resize(n); dp[1].resize(n);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
		}
		dp[0][0] = s[0][0];
		dp[1][0] = s[1][0];

		if (n > 1) {
			dp[0][1] = s[0][1] + s[1][0];
			dp[1][1] = s[1][1] + s[0][0];
		}

		for (int i = 2; i < n; i++) {
			dp[0][i] = max(s[0][i] + dp[1][i - 1], s[0][i] + dp[0][i - 2]);
			dp[0][i] = max(dp[0][i], s[0][i] + dp[1][i - 2]);

			dp[1][i] = max(s[1][i] + dp[0][i - 1], s[1][i] + dp[0][i - 2]);
			dp[1][i] = max(dp[1][i], s[1][i] + dp[1][i - 2]);
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";

		s[0].clear(); s[1].clear();
		dp[0].clear(); dp[1].clear();
	}

	return 0;
}