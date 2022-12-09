#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, cost, res;
	cin >> N;

	vector<vector<int>> c(3);
	int dp[3][1000];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost;
			c[j].push_back(cost);
			if (i == 0) dp[j][i] = cost;
		}
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cost = c[j][i];
			if (j == 0) dp[j][i] = min(cost + dp[1][i - 1], cost + dp[2][i - 1]);
			else if (j == 1) dp[j][i] = min(cost + dp[0][i - 1], cost + dp[2][i - 1]);
			else if (j == 2) dp[j][i] = min(cost + dp[0][i - 1], cost + dp[1][i - 1]);
		}
	}

	res = min(dp[0][N - 1], dp[1][N - 1]);
	res = min(res, dp[2][N - 1]);
	cout << res;
	return 0;
}