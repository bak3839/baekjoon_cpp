#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph(32001);
bool visited[32001];
int cnt, N;

void ts_dfs(int v) {
	visited[v] = true;

	if (cnt == N) return;

	for (int i = 0;i < graph[v].size();i++) {
		int u = graph[v][i];
		if (!visited[u]) ts_dfs(u);
	}

	cout << v << " ";
	++cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int M, s, e;

	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		cin >> s >> e;
		graph[e].push_back(s);
	}

	for (int i = 1;i <= N;i++) {
		if (!visited[i]) ts_dfs(i);
		if (cnt == N) break;
	}

	return 0;
}