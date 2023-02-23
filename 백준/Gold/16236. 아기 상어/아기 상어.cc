#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

int map[20][20];
bool eat;
bool visited[20][20];
int N, fish, Lv = 2, Exp, ans, bx, by;
int mv1[4] = { -1, 0, 0, 1 };
int mv2[4] = { 0, -1, 1, 0 };

void bfs(int x, int y) {
	queue<vector<int>> q;
	q.push({ x, y, 0 });
	visited[x][y] = true;
	int time = 0;

	while (!q.empty() && fish) {
		int x = q.front()[0];
		int y = q.front()[1];
		int cnt = q.front()[2];
		q.pop();

		if (map[x][y] > 0 && map[x][y] < Lv && time == cnt) {
			if ((bx > x) || (bx == x && by > y)) {
				by = y;
				bx = x;
				continue;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + mv1[i];
			int ny = y + mv2[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			int next = map[nx][ny];
			if (visited[nx][ny] || next > Lv) continue;

			if (1 <= next && next < Lv && !eat) {
				eat = true;
				bx = nx;
				by = ny;
				time = cnt + 1;
				ans += time;
			}
			else {
				visited[nx][ny] = true;
				q.push({ nx, ny, cnt + 1 });
			}		
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				bx = i; by = j;
				map[bx][by] = 0;
			}
			else if (map[i][j] > 0) fish++;
		}
	}
	
	while (1) {
		bfs(bx, by);
		
		if (eat && fish) {
			eat = false;
			Exp++;
			fish--;
			map[bx][by] = 0;

			if (Lv == Exp) {
				Exp = 0;
				Lv++;
			}	
			memset(visited, false, sizeof(visited));
		}
		else break;		
	}

	cout << ans;
	return 0;
}