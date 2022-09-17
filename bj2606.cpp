#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
bool visited[101];
vector<vector<int>> graph(101);

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int n = graph[x][i];
		if (!visited[n]) {
			++cnt;
			dfs(n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, r, c;
	cin >> N >> M;
	

	for (int i = 0; i < M; i++) {
		cin >> r >> c;
		graph[r].push_back(c);
		graph[c].push_back(r);
	}
	dfs(1);

	cout << cnt;
	return 0;
}