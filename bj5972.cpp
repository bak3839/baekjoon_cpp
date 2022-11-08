#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> d(50001, 50000001);
vector<vector<pair<int, int>>> graph(50001);

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
    cin.tie(0);
    cout.tie(0);

    int V, E, s, start, end, cost;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
        graph[end].push_back({ start, cost });
    }

    dijkstra(1, V);

    cout << d[V];
    return 0;
}