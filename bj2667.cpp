#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt = 0, N;
int graph[26][26] = { 0, };


void dfs(int x, int y) {
	if ((x >= 0 && x < N) && (y >= 0 && y < N)) {
		if (graph[x][y]) {
			graph[x][y] = 0;
			++cnt;
			dfs(x - 1, y);
			dfs(x + 1, y);
			dfs(x, y - 1);
			dfs(x, y + 1);
		}
	}
}

int main() {
	vector<int> res;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1) dfs(i, j);
			if (cnt != 0) res.push_back(cnt);
			cnt = 0;
		}
	}

	cout << res.size() << "\n";
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) cout << res[i] << "\n";
	return 0;
}