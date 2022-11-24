#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> d(100001, 100000000001);
vector<vector<pair<int, int>>> graph(100001);
vector<int> ward;
int N, M;

void dijkstra(int s) {
    priority_queue<pair<ll, int>> pq;

    pq.push({ 0, s });
    d[s] = 0;

    while (!pq.empty()) {
        ll dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (d[now] < dist && now == N - 1) break;

        if (d[now] < dist) continue; // 이미 최단 경로를 찾은 정점이면 통과

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;       // 다음 정점번호
            ll cost = dist + graph[now][i].second; // 다음 정점까지 가는 비용
            
            // 다음 정점으로 가는 비용중 최단 거리 + 적시야가 없거나 넥서스일때
            if (cost < d[next]) { 
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

    int s, e, t;
    cin >> N >> M;   

    for (int i = 0; i < N; i++) { // 적 시야
        cin >> t;
        ward.push_back(t);
    }

    for (int i = 0; i < M; i++) { // 양방향 연결
        cin >> s >> e >> t;
        if (e != N - 1 && s != N - 1 && ward[s]) continue;
        if (e != N - 1 && s != N - 1 && ward[e]) continue;
        graph[s].push_back({ e,t });
        graph[e].push_back({ s,t });
    }

    dijkstra(0);

    if (d[N - 1] != 100000000001) cout << d[N - 1];
    else cout << -1;

    return 0;
}