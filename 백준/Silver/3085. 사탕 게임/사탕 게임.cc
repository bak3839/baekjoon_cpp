#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans;
vector<vector<char>> map;
vector<vector<bool>> visit;

void row_find(int x) {
	int cnt = 1;

	for (int i = 0; i < N - 1; i++) {
		if (map[x][i] == map[x][i + 1]) cnt++;
		else cnt = 1;

		ans = max(ans, cnt);
	}
}
void col_find(int y) {
	int cnt = 1;

	for (int i = 0; i < N - 1; i++) {
		if (map[i][y] == map[i + 1][y]) cnt++;
		else cnt = 1;

		ans = max(ans, cnt);
	}
}

void search(int x1, int y1, int x2, int y2) {
	int cnt = 1;

	if (x1 == x2) {
		row_find(x1);
		col_find(y1);
		col_find(y2);
	}

	else {
		row_find(x1);
		row_find(x2);
		col_find(y1);
	}
}

void change(int x1, int y1, int x2, int y2) {
	char tmp = map[x1][y1];
	map[x1][y1] = map[x2][y2];
	map[x2][y2] = tmp;
}

void solve(int x, int y) {
	if (y == N) {
		x++; y = -1;
		if (x == N) return;
	}

	else {
		if (x + 1 < N && map[x][y] != map[x + 1][y]) {
			change(x, y, x + 1, y);
			search(x, y, x + 1, y);
			change(x, y, x + 1, y);
		}

		if (y + 1 < N && map[x][y] != map[x][y + 1]) {
			change(x, y, x, y + 1);
			search(x, y, x, y + 1);
			change(x, y, x, y + 1);
		}
	}

	solve(x, y + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	map.resize(N, vector<char>(N));
	visit.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) row_find(i);
	for (int i = 0; i < N; i++) col_find(i);

	solve(0, 0);

	cout << ans;
	return 0;
}