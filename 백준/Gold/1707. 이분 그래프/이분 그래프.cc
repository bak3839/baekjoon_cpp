#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int>> graph(20001);
bool visited[20001];
short color[20001];
bool pass;

void dfs(int v) {
	visited[v] = true;

	for (int i = 0;i < graph[v].size();i++) {
		int u = graph[v][i];

		if (visited[u] && color[v] == color[u]) {
			pass = false;
			return;
		}

		if (!visited[u]) {
			if (color[v] == 1) color[u] = 2;
			else if (color[v] == 2) color[u] = 1;
			dfs(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, s, e, N, M;
	cin >> T;

	while (T--) {
		pass = true;

		cin >> N >> M;
		for (int i = 0;i < M;i++) {
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		for (int i = 1;i <= N;i++) {
			if (!visited[i]) {
				color[i] = 1;
				dfs(i);
			}
			if (!pass) break;
		}

		if (pass) cout << "YES\n";
		else cout << "NO\n";

		for (int i = 1;i <= N;i++) graph[i].clear();
		memset(visited, 0, N + 1);
		memset(color, 0, N + 1);
	}
	return 0;
}