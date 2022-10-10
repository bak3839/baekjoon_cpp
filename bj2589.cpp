#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

char map[50][50];
int dis[50][50];

int N, M, cnt, res = 0;

int m1[4] = { -1, 1, 0, 0 };
int m2[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + m1[i];
			int ny = y + m2[i];

			if ((0 <= nx && nx < N) && (0 <= ny && ny < M) && map[nx][ny] == 'L' && dis[nx][ny] == 0) {
				dis[nx][ny] = dis[x][y] + 1;
				res = max(res, dis[nx][ny]);
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> v;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if(map[i][j] == 'L') v.push_back({i, j});
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		dis[x][y] = 1;
		bfs(x, y);
		memset(dis, 0, sizeof(dis));
	}
	
	cout << res - 1;
	return 0;
}