#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, res;
	cin >> N;

	vector<int> v(N + 1);
	vector<int> dp(N + 1);

	for (int i = 1; i <= N; i++) cin >> v[i];
	dp[1] = v[1];
	res = v[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = v[i];
		for (int j = i - 1; j >= 1; j--) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + v[i]);
			}
		}
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}