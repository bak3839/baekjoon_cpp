#include <iostream>
#include <vector>

using namespace std;

bool visited[500][500];

int n, m, cnt;
short mv1[4] = { 0,0,-1,1 };
short mv2[4] = { -1,1,0,0 };
vector<vector<short>> map;

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		short nx = x + mv2[i];
		short ny = y + mv1[i];
		if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
			if (!visited[nx][ny] && map[nx][ny] == 1) dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int num, res = 0, picture = 0;
	cin >> n >> m;

	map.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			map[i].push_back(num);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				dfs(i, j);
				picture++;
			}
			res = max(res, cnt);
			cnt = 0;
		}
	}

	cout << picture << "\n" << res;
	return 0;
}