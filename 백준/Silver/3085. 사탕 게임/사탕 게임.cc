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

void search() {
	int cnt;

	for (int i = 0; i < N; i++) {
		cnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) cnt++;
			else cnt = 1;

			ans = max(ans, cnt);
		}
	}

	for (int i = 0; i < N; i++) {
		cnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[j][i] == map[j + 1][i]) cnt++;
			else cnt = 1;

			ans = max(ans, cnt);
		}
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
			search();
			change(x, y, x + 1, y);
		}

		if (y + 1 < N && map[x][y] != map[x][y + 1]) {
			change(x, y, x, y + 1);
			search();
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

	solve(0, 0);

	cout << ans;
	return 0;
}