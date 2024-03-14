#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, S, E, C;
vector<pii> d;
vector<vector<pii>> graph;

void Solution() {
    priority_queue<pii> pq;
    pq.push({ 0, S });
    d[S].first = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now].first < dist && now == E) break;
        if (d[now].first < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = dist + graph[now][i].second;

            if (d[next].first > cost && cost <= C) {
                if (d[next].second != 0 && d[next].second < d[now].second) continue;

                d[next].first = cost;
                d[next].second = max(d[now].second, graph[now][i].second);
                pq.push({ -cost, next });
            }
        }
    }

    if (d[E].second == 0) cout << -1;
    else cout << d[E].second;
}

void Input() {
    int v1, v2, c;
    cin >> N >> M >> S >> E >> C;

    graph.resize(N + 1);
    d.resize(N + 1, { 2100000000, 0 });

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2 >> c;

        graph[v1].push_back({ v2, c });
        graph[v2].push_back({ v1, c });
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
