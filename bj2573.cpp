#include <iostream>
#include <cstring>

using namespace std;

short N, M;
short map[300][300];
bool visited[300][300];
bool pass = true;

bool dfs(int x, int y) {
	short sea = 0;

	if ((0 > x || x >= N) || (0 > y || y >= M) || visited[x][y]) return false;

	if ((0 <= x && x < N) && (0 <= y && y < M)) {
		if (map[x][y] == 0) return true;

		else if(!visited[x][y]) {
			visited[x][y] = true;

			if (dfs(x - 1, y)) sea++;
			if (dfs(x + 1, y)) sea++;
			if (dfs(x, y - 1)) sea++;
			if (dfs(x, y + 1)) sea++;

			short sum = map[x][y] - sea;

			if (sum < 0) map[x][y] = 0;

			else map[x][y] = sum;

			return false;
		}
	}
}

void check(int x, int y) {
	if ((0 <= x && x < N) && (0 <= y && y < M)) {
		if (!visited[x][y] && map[x][y]) {
			visited[x][y] = true;

			check(x - 1, y);
			check(x + 1, y);
			check(x, y - 1);
			check(x, y + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	short year = 0, cnt = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		memset(visited, false, sizeof(visited));
		cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j] != 0) {
					check(i, j);
					++cnt;
				}
			}
		}

		if (!cnt) {
			cout << 0;
			return 0;
		}

		else if (cnt >= 2) {
			cout << year;
			return 0;
		}	

		++year;

		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && map[i][j] != 0) {
					dfs(i, j);
				}
			}
		}
	}
	return 0;
}