#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, res, dist, cnt;
vector<bool> visited;
vector<vector<int>> road;

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x, 0 });
	visited[x] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int cost = q.front().second;
		bool pass = false;
		q.pop();

		for (int i = 0; i < road[now].size(); i++) {
			int next = road[now][i];

			if (!visited[next]) {
				q.push({ next, cost + 1 });
				visited[next] = true;
				pass = true;
			}
		}

		if (!pass) {
			if (res == 0 || dist < cost) {
				res = now;
				dist = cost;
				cnt = 1;
			}

			else if (dist == cost) {
				if (now < res) res = now;
				++cnt;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	road.resize(N + 1);
	visited.resize(N + 1);
	int v1, v2;

	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		road[v1].push_back(v2);
		road[v2].push_back(v1);
	}

	bfs(1);

	cout << res << " " << dist << " " << cnt;
	return 0;
}