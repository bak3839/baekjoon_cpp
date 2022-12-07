#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K, W, V;

	cin >> N >> K;
	vector<pair<int,int>> v(N + 1);
	
	for (int i = 1;i <= N;i++) cin >> v[i].first >> v[i].second;

	for (int i = 1;i <= N;i++) {
		W = v[i].first; V = v[i].second;

		for (int j = 1;j <= K;j++) {
			if (j - W < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
		}
	}

	cout << dp[N][K];
	return 0;
}