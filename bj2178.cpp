#include <iostream>
#include <queue>

using namespace std;

short map[100][100];
int N, M;
int m1[4] = { -1, 1, 0, 0 };
int m2[4] = { 0, 0, -1, 1 };

short bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + m1[i];
			int ny = y + m2[i];

			if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
				if (map[nx][ny] == 1) {
					map[nx][ny] = map[x][y] + 1;
					q.push({ nx, ny });
				}
			}

			if (nx == N - 1 && ny == M - 1) return map[nx][ny];
		}
	}
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	cout << bfs();
	return 0;
}