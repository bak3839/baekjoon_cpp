#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> connect(1001);
vector<pair<int, int>> d(1001);
vector<vector<pair<int, int>>> graph(1001, vector<pair<int, int>>(1001));

void dijkstra(int start, int end) {
    priority_queue<pair<int, int>> pq;

    pq.push({ 0,start });
    d[start].first = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now].first < dist && now == end) break;

        if (d[now].first < dist) continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = dist + graph[now][i].second;

            if (cost < d[graph[now][i].first].first)
            {
                d[graph[now][i].first].first = cost;
                d[graph[now][i].first].second = now;
                pq.push({ -cost, graph[now][i].first });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, start, end, cost;;

    cin >> N >> M;

    fill(d.begin() + 1, d.begin() + N + 1, make_pair(2000000002, 0));

    for (int i = 0; i < M; i++) {
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
    }

    cin >> start >> end;

    dijkstra(start, end);

    vector<int> res;

    int v = end;
    res.push_back(v);

    while (v != start) {
        v = d[v].second;
        res.push_back(v);
    }

    cout << d[end].first << "\n";
    cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";

    return 0;
}