#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> dp(N + 1, vector<int>(10, 0));
	for (int i = 1; i <= N; i++) dp[i][0] = 1;

	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= 9; i++) {
			dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % 10007;
		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[N][i];
		sum %= 10007;
	}

	cout << sum;
	return 0;
}