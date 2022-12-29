#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, num;
	cin >> N >> M;
	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			v[i][j] = v[i][j - 1] + num;
		}
	}

	int x1, x2, y1, y2;
	for (int i = 0; i < M; i++) {
		int res = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j <= x2; j++) {
			res += v[j][y2] - v[j][y1 - 1];
		}

		cout << res << "\n";
	}
	return 0;
}