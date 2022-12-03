#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph(1001);
short visited[1001];
vector<int> res;
int N;

int ts_dfs(int v) {
	int p = 1;
	visited[v] = 2;

	for (int i = 0;i < graph[v].size();i++) {
		int u = graph[v][i];
		if (visited[u] == 2) return 0;
		if (visited[u] == 0) p = ts_dfs(u);
		if (p == 0) return 0;
	}

	res.push_back(v);
	visited[v] = 1;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int M, s, n;

	cin >> N >> M;
	vector<int> v;

	for (int i = 0;i < M;i++) {
		cin >> n;
		for (int j = 0;j < n;j++) {
			cin >> s;
			v.push_back(s);

			if (j > 0) {
				graph[v[j]].push_back(v[j - 1]);
			}
		}
		v.clear();
	}

	int p = 1;
	for (int i = 1;i <= N;i++) {
		if (!visited[i]) p = ts_dfs(i);
		if (res.size() == N || p == 0) break;
	}

	if (p == 1) {
		for (int i = 0;i < N;i++) {
			cout << res[i] << "\n";
		}
	}
	else cout << 0;

	return 0;
}