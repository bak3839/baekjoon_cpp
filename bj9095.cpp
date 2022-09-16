#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int dp[12] = { 0, };
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		if (dp[n] == 0) {
			for (int j = 4; j <= n; j++) {
				dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
			}
		}
		cout << dp[n] << "\n";
	}
	return 0;
}