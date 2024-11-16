#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, res = 0, maxCnt = -1, K, M;
	cin >> N;

	string name, ans;

	for (int i = 0; i < N; i++) {
		int cnt = 0;

		cin >> name >> K >> M;

		while (K <= M) {
			cnt++;
			M = M - K + 2;
		}

		res += cnt;

		if (cnt > maxCnt) {
			maxCnt = cnt;
			ans = name;
		}
	}

	cout << res << "\n" << ans;
	return 0;
}