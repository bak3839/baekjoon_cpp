#include <iostream>

using namespace std;

int road[500][500];
int dp[500][500];

int cnt = 0, M, N;

int m1[4] = { -1, 1, 0, 0 };
int m2[4] = { 0, 0, -1, 1 };

int dfs(int x, int y) {
	if ((0 > x || x >= M) || (0 > y || y >= N)) return 0;
	if (x == M - 1 && y == -1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + m1[i];
		int ny = y + m2[i];

		if (road[nx][ny] < road[x][y]) {
			dp[x][y] += dfs(nx, ny);
		} 
	}

	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> road[i][j];
			dp[i][j] = -1;
		}
	}

	dp[M - 1][N - 1] = 1;
	cout << dfs(0, 0);
	return 0;
}