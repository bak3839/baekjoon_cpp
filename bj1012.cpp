#include <iostream>
#include <vector>

using namespace std;

int graph[50][50] = { 0, };
int cnt = 0, M, N;

void dfs(int x, int y) {
	if ((x >= 0 && x < N) && (y >= 0 && y < M)) {
		if (graph[x][y]) {
			graph[x][y] = 0;
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

	int T, K, r, c;
	cin >> T;

	while (T--) {
		cin >> M >> N >> K;
		cnt = 0;

		for (int i = 0; i < K; i++) {
			cin >> c >> r;
			graph[r][c] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j]) {
					++cnt;
					dfs(i, j);
				}
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}