#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int n, m, start, finish;
vector<int> d;
vector<vector<pii>> graph;

void Solution() {
    priority_queue<pii> pq;
    pq.push({ 0, start });
    d[start] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist && now == finish) break;
        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = dist + graph[now][i].second;
            
            if (d[next] > cost) {
                d[next] = cost;
                pq.push({ -cost, next });
            }
        }
    }

    cout << d[finish];
}

void Input() {
    int s, e, c;
    cin >> n >> m;

    graph.resize(n + 1);
    d.resize(n + 1, 2100000000);

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> c;

        graph[s].push_back({ e, c });
        graph[e].push_back({ s, c });
    }

    cin >> start >> finish;
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
