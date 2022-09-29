#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

short map[100][100];

int M, N, K, cnt = 0;


void dfs(int x, int y) {
	if ((0 <= x && x < M) && (0 <= y && y < N)) {
		if (!map[x][y]) {
			map[x][y] = 1;
			++cnt;

			dfs(x, y - 1);
			dfs(x, y + 1);
			dfs(x - 1, y);
			dfs(x + 1, y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> res;
	int lx, ly, rx, ry;
	cin >> M >> N >> K;

	while (K--) {
		cin >> lx >> ly >> rx >> ry;
		ly = M - ly - 1; ry = M - ry - 1;

		for (int j = ly; j > ry; j--) {
			for (int i = lx; i < rx; i++) {
				map[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j]) {
				dfs(i, j);
				res.push_back(cnt);
			}
			cnt = 0;
		}
	}
	
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
	return 0;
}