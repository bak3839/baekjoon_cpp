#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, V, E;
int f[2];
vector<int> H, d;
vector<vector<pii>> graph;

int dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0 ,start });
    d[start] = 0;

    int cost, dist, now, next, cnt = 0, res = 0;

    while (!pq.empty()) {
        now = pq.top().second;
        dist = pq.top().first;
        pq.pop();

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            next = graph[now][i].first;
            cost = dist + graph[now][i].second;

            if (cost >= d[next]) continue;

            d[next] = cost;
            pq.push({ cost, next });
        }
    }

    res += d[f[0]] == 2100000000 ? -1 : d[f[0]];
    res += d[f[1]] == 2100000000 ? -1 : d[f[1]];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0, v1, v2, cost;

    cin >> N >> V >> E;
    cin >> f[0] >> f[1];

    H.resize(N);
    graph.resize(V + 1);
    d.resize(V + 1, 2100000000);

    for (int i = 0; i < N; i++)
        cin >> H[i];

    for (int i = 0; i < E; i++) {
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back({ v2, cost });
        graph[v2].push_back({ v1, cost });
    }

    for (int i = 0; i < N; i++) {
        ans += dijkstra(H[i]);
        fill(d.begin(), d.end(), 2100000000);
    }

    cout << ans;
    return 0;
}