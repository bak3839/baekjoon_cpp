#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int graph[100][100][100];
int res = 0, cnt = 0, M, N, H;

int mv1[6] = { -1, 1, 0, 0, 0, 0 };
int mv2[6] = { 0, 0, -1, 1, 0, 0 };
int mv3[6] = { 0, 0, 0, 0, -1, 1 };
queue<vector<int>> q;

void bfs() {
	int x, y, h;

	while (!q.empty()) {
		x = q.front()[0];
		y = q.front()[1];
		h = q.front()[2];
		q.pop();

		for (int i = 0; i < 6; i++) {

			int nx = x + mv1[i];
			int ny = y + mv2[i];
			int nh = h + mv3[i];

			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M) && (nh >= 0 && nh < H)) {
				if (!graph[nh][nx][ny]) {
					graph[nh][nx][ny] = graph[h][x][y] + 1;
					res = max(res, graph[nh][nx][ny]);
					q.push({ nx,ny,nh });
					--cnt;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> graph[k][i][j];
				if (graph[k][i][j] == 0) ++cnt;

				else if (graph[k][i][j] == 1) q.push({ i,j,k });
			}
		}
	}
	
	if (cnt == 0) {
		cout << 0;
		return 0;
	}

	bfs();

	if (!cnt) cout << res - 1;
	else cout << -1;
	return 0;
}