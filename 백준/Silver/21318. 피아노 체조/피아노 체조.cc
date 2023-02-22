#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, Q, n, prev, x, y;
	cin >> N;
	vector<int> sum(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> n;

		if (i == 1) {
			prev = n;
			continue;
		}

		if (n < prev) sum[i - 1] += 1;
		sum[i] = sum[i - 1];
		prev = n;
	}
	
	cin >> Q;

	while (Q--) {
		int ans;
		cin >> x >> y;

		ans = sum[y] - sum[x - 1];
		if (sum[y] > sum[y - 1]) ans--;

		cout << ans << "\n";
	}
	return 0;
}