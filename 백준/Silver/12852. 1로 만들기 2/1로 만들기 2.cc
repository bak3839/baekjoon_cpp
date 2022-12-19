#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> dp(N + 1, make_pair(1000001, 0));

	dp[0] = make_pair(0, 0);
	dp[1] = make_pair(0, 0);
	if (N >= 2) dp[2] = make_pair(1, 1);
	if (N >= 3) dp[3] = make_pair(1, 1);

	for (int i = 4;i <= N;i++) {
		if (i % 2 == 0 && dp[i].first > dp[i / 2].first + 1) {
			dp[i].first = dp[i / 2].first + 1;
			dp[i].second = i / 2;
		}

		if (i % 3 == 0 && dp[i].first > dp[i / 3].first + 1) {
			dp[i].first = dp[i / 3].first + 1;
			dp[i].second = i / 3;
		}
		
		if (dp[i].first > dp[i - 1].first + 1) {
			dp[i].first = dp[i - 1].first + 1;
			dp[i].second = i - 1;
		}
	}

	cout << dp[N].first << "\n";
	int t = N;

	while (t != 0) {
		cout << t << " ";
		t = dp[t].second;
	}
	return 0;
}