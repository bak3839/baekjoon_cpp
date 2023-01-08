#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> d;
vector<bool> visited;
vector<vector<int>> pre;
vector<vector<pair<int, int>>> graph;

void dijkstra(int start, int end) {
    priority_queue<pair<int, int>> pq;

    pq.push({ 0,start });
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist && now == end) break;

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = dist + graph[now][i].second;

            if (cost < d[graph[now][i].first])
            {
                d[graph[now][i].first] = cost;
                pq.push({ -cost, graph[now][i].first });
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, E, P, v1, v2, w;
	cin >> N >> E >> P;

	d.resize(N + 1, 160000001);
	pre.resize(N + 1);
    pre[1].push_back(0);
	graph.resize(N + 1);
    visited.resize(N + 1, false);

	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> w;
		graph[v1].push_back({ v2, w });
		graph[v2].push_back({ v1, w });
	}

    dijkstra(1, N);
    int res = d[N], pcost = d[P];
    d.clear();
    d.resize(N + 1, 160000001);
    dijkstra(P, N);

    if(res == pcost + d[N]) cout << "SAVE HIM";
    else cout << "GOOD BYE";

	return 0;
}