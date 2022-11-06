#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<vector<pair<int, int>>>> graph(2, vector<vector<pair<int, int>>>(1001));
int d[2][1001];
int INF = 1e9 + 7;

void dijkstra(int start, int index){
    priority_queue<pair<int, int>> pq;

    pq.push({ 0,start });
    d[index][start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[index][now] < dist) continue; 

        for (int i = 0; i < graph[index][now].size(); i++)
        {
            int cost = dist + graph[index][now][i].second;
                                                  
            if (cost < d[index][graph[index][now][i].first])
            {
                d[index][graph[index][now][i].first] = cost;
                pq.push({ -cost, graph[index][now][i].first });
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    fill(&d[0][0], &d[1][1001], INF);
    int N, M, X, start, end, cost, res = 0;
    
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        cin >> start >> end >> cost;
        graph[0][start].push_back({ end, cost });
        graph[1][end].push_back({ start, cost });
    }

    dijkstra(X, 0);
    dijkstra(X, 1);

    for (int i = 1; i <= N; i++) {
        res = max(res, d[0][i] + d[1][i]);
    }
    cout << res;

	return 0;
}