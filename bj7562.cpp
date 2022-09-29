#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, end_x, end_y, start_x, start_y;
bool visited[300][300];
short map[400][400];

int m1[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int m2[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

int bfs() {
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == end_x && y == end_y) return map[x][y];


		for (int i = 0; i < 8; i++) {
			int nx = x + m1[i];
			int ny = y + m2[i];

			if ((0 <= nx && nx < N) && (0 <= ny && ny < N) && !visited[nx][ny]) {
				visited[nx][ny] = true;
				map[nx][ny] = map[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;

		cout << bfs() << "\n";

		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
	}

	return 0;
}