#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph(10001);
vector<int> d(10001, INT_MAX);
int cnt;

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	d[s] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;

		for (int i = 0;i < graph[now].size();i++) {
			int next = graph[now][i].first;
			int cost = dist + graph[now][i].second;			

			if (d[next] > cost) {
				if (d[next] == INT_MAX) ++cnt;
				pq.push({ -cost, next });
				d[next] = cost;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, D, c, T, s, e, t, res = 0;
	cin >> T;

	while (T--) {
		cin >> n >> D >> c;

		for (int i = 0;i < D;i++) {
			cin >> e >> s >> t;
			graph[s].push_back({ e,t });
		}

		dijkstra(c);

		for (int i = 1;i <= n;i++) {
			if (d[i] != INT_MAX && res < d[i]) res = d[i];
		}

		cout << cnt + 1 << " " << res << "\n";

		cnt = 0; res = 0;
		graph.clear();
		graph.resize(10001);
		fill(d.begin() + 1, d.begin() + n + 1, INT_MAX);
	}

	return 0;
}