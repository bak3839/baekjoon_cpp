#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<short>> map;
int visited[1001][1001][2];

int res = 3000, N, M;
int mv1[4] = { 0, 0 ,-1, 1 };
int mv2[4] = { -1, 1, 0, 0 };

int bfs() {
	queue<vector<int>> q;
	visited[1][1][1] = 1;
	q.push({ 1, 1, 1 });

	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int chance = q.front()[2];
		q.pop();

		if (x == N && y == M) {
			return visited[x][y][chance];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + mv1[i];
			int ny = y + mv2[i];

			if (0 < nx && nx <= N && 0 < ny && ny <= M) {
				if (map[nx][ny] == 1 && chance) {
					q.push({ nx, ny, 0 });
					visited[nx][ny][chance - 1] = visited[x][y][chance] + 1;
				}

				else if (map[nx][ny] == 0 && visited[nx][ny][chance] == 0) {
					q.push({ nx, ny, chance });
					visited[nx][ny][chance] = visited[x][y][chance] + 1;
				}
			}
		}
	}

	return - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> N >> M;

	map.resize(N + 1, vector<short>(M + 1));

	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			map[i][j] = s[j - 1] - 48;
		}
	}

	cout << bfs();

	return 0;
}