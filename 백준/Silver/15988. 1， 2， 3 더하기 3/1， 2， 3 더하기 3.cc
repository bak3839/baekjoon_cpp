#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, N, before = 4;
	cin >> T;
	vector<ll> dp(1000001);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (T--) {
		cin >> N;
		for (int i = before; i <= N; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		}
		if (before < N) before = N + 1;
		cout << dp[N] << "\n";
	}
	return 0;
}