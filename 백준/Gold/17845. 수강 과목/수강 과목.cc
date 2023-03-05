#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

	int l, t;

	for (int i = 1; i <= K; i++) {
		cin >> l >> t;

		for (int j = 1; j <= N; j++) {
			if (j - t < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + l);
		}
	}

	cout << dp[K][N];
	return 0;
}