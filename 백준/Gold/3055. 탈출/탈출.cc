#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<char>> map;
queue<pair<int, int>> water;

bool pass;
int N, M, res;
int mv1[4] = { 0, 0 ,-1, 1 };
int mv2[4] = { -1, 1, 0, 0 };

void moveWater() {
	int size = water.size();

	for (int i = 0; i < size; i++) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + mv1[i];
			int ny = y + mv2[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (map[nx][ny] == '.' || map[nx][ny] == 'S' || map[nx][ny] == 'x') {
					water.push({ nx, ny });
					map[nx][ny] = '*';
				}
			}
		}
	}
}

void bfs(int x, int y) {
	queue<vector<int>> q;
	q.push({ x, y, 0 });

	while (!q.empty()) {
		int size = q.size();

		for (int j = 0; j < size; j++) {
			int x = q.front()[0];
			int y = q.front()[1];
			int cnt = q.front()[2];
			q.pop();

			if (map[x][y] == '*') continue;

			for (int i = 0; i < 4; i++) {
				int nx = x + mv1[i];
				int ny = y + mv2[i];

				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (map[nx][ny] == '.' || map[nx][ny] == 'D') {
						if (map[nx][ny] == 'D') {
							pass = true;
							res = cnt + 1;
							return;
						}
						q.push({ nx, ny, cnt + 1 });
						map[nx][ny] = 'x';
					}
				}
			}
		}
		moveWater();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	pair<int, int> s;
	cin >> N >> M;
	map.resize(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') water.push({ i, j });
			else if (map[i][j] == 'S') s = { i, j };
		}
	}

	bfs(s.first, s.second);


	if (pass) cout << res;
	else cout << "KAKTUS";
	return 0;
}