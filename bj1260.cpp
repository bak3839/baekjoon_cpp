#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, V;
vector<vector<int>> v(1001);
bool visited[1001];

void dfs(int x) {
	visited[x] = true;
	sort(v[x].begin(), v[x].end());
	cout << x << " ";
	for (int i = 0; i < v[x].size(); i++) {
		if(!visited[v[x][i]]) dfs(v[x][i]);
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int next = q.front();
		visited[next] = true;
		cout << next << " ";
		q.pop();

		for (int i = 0; i < v[next].size(); i++) {
			if (!visited[v[next][i]]) {
				q.push(v[next][i]);
				visited[v[next][i]] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r, c;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> r >> c;
		v[r].push_back(c);
		v[c].push_back(r);
	}
	
	dfs(V);
	cout << "\n";

	memset(visited, false, sizeof(visited));

	bfs(V);
	return 0;
}