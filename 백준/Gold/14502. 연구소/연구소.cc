#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, safe, res, cnt_wall;
int copy_map[8][8];
int map[8][8];
vector<pair<int, int>> virus;

int m1[4] = { -1, 1, 0, 0 };
int m2[4] = { 0, 0, -1, 1 };

void map_cpy(int a[][8], int b[][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void bfs() {
	queue<pair<int, int>> q;
	int cnt = 0;
	int tmp[8][8];
	map_cpy(tmp, copy_map);

	for (int i = 0; i < virus.size(); i++) q.push(virus[i]);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + m1[i];
			int ny = y + m2[i];

			if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
				if (tmp[nx][ny] == 0) {
					tmp[nx][ny] = 2;
					++cnt;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	res = max(res, (safe - 3 - cnt));
}

void wall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 0) {
				copy_map[i][j] = 1;
				wall(cnt + 1);
				copy_map[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) ++safe;
			else if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map_cpy(copy_map, map);
				copy_map[i][j] = 1;
				wall(1);
				copy_map[i][j] = 0;
			}
		}
	}

	cout << res;
	return 0;
}