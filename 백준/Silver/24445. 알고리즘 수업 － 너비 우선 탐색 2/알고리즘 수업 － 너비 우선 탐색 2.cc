#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> order;

bool cmp(int a, int b) {
	return b < a;
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = true;

	int cnt = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		order[now] = cnt++;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];

			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, R, s, e;
	cin >> N >> M >> R;
	graph.resize(N + 1);
	visited.resize(N + 1, false);
	order.resize(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	bfs(R);

	for (int i = 1; i <= N; i++) cout << order[i] << "\n";
	return 0;
}