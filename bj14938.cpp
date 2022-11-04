#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> item(101);
vector<int> d(101, 16); // 최단 거리 테이블 만들기
vector<vector<pair<int, int>>> graph(101, vector<pair<int, int>>(101));
int n, m, r, res = 0;

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq; // 거리, 노드 인덱스

    pq.push({ 0,start }); //시작 노드로 가기위한 최단 경로는 0으로 설정하여, 큐에 삽입.
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first; //현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();

        if (d[now] < dist || dist > m) continue;

        for (int i = 0; i < graph[now].size(); i++) // 해당 노드에서 연결된 노드들을 우선순위 큐에 삽입
        {
            int cost = dist + graph[now][i].second; // 거쳐서 가는 노드의 비용을 계산
            
            if (cost < d[graph[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
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

    int t, start, end, cost;
    cin >> n >> m >> r;

    for (int i = 1;i <= n;i++) cin >> item[i];

    for (int i = 0;i < r;i++) {
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
        graph[end].push_back({ start, cost });
    }

    for (int i = 1;i <= n;i++) {
        int sum = 0;
        dijkstra(i);
        for (int j = 1;j <= n;j++) {
            if (d[j] <= m) sum += item[j];
        }
        res = max(res, sum);
        fill(d.begin(), d.end(), 16);
    }

    cout << res;
    return 0;
}