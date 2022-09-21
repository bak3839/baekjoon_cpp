#include <iostream>
#include <vector>

using namespace std;

char graph[100][100];
bool visited[100][100];
int N;

void dfs1(int i, int j, char ch) {
	if ((0 <= i && i < N) && (0 <= j && j < N)) {
		if (!visited[i][j] && graph[i][j] == ch) {
			visited[i][j] = true;
			dfs1(i, j + 1, graph[i][j]);
			dfs1(i, j - 1, graph[i][j]);
			dfs1(i - 1, j, graph[i][j]);
			dfs1(i + 1, j, graph[i][j]);
		}
	}
}

void dfs2(int i, int j, char ch) {
	if ((0 <= i && i < N) && (0 <= j && j < N)) {
		if (ch == graph[i][j] || (ch == 'R' && graph[i][j] == 'G') || (ch == 'G' && graph[i][j] == 'R')) {
			graph[i][j] = '0';
			dfs2(i, j + 1, ch);
			dfs2(i, j - 1, ch);
			dfs2(i - 1, j, ch);
			dfs2(i + 1, j, ch);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt1 = 0, cnt2 = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				++cnt1;
				dfs1(i, j, graph[i][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char rgb = graph[i][j];
			if (rgb == 'R' || rgb == 'G' || rgb == 'B') {
				++cnt2;
				dfs2(i, j, rgb);
			}
		}
	}

	cout << cnt1 << " " << cnt2;
	return 0;
}