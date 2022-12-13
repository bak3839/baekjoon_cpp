#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	if (N % 2 != 0) {
		cout << 0;
		return 0;
	}

	vector<ll> dp(N + 1, 0);

	dp[2] = 3;
	dp[4] = 11;

	for (int i = 6; i <= N; i = i + 2) {
		dp[i] = dp[i - 2] * 4 - dp[i - 4];
	}

	cout << dp[N];
	return 0;
}