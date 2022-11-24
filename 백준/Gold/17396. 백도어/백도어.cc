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

        if (d[now] < dist) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            ll cost = dist + graph[now][i].second;
            
            if (cost < d[next] && (!ward[next] || next == N - 1)) { 
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

    for (int i = 0; i < N; i++) {
        cin >> t;
        ward.push_back(t);
    }

    for (int i = 0; i < M; i++) {
        cin >> s >> e >> t;
        graph[s].push_back({ e,t });
        graph[e].push_back({ s,t });
    }

    dijkstra(0);

    if (d[N - 1] != 100000000001) cout << d[N - 1];
    else cout << -1;

    return 0;
}