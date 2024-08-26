#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int N, M, R;
vector<bool> visited;
vector<vector<int>> graph;

void Solution() {
    queue<int> q;
    q.push(R);
    visited[R] = true;

    ll ans = 0, depth = 1, count = 2;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int n = q.front();
            q.pop();

            for(int i = 0; i < graph[n].size(); i++) {
                int next = graph[n][i];

                if(visited[next]) continue;

                ans += (depth * count++);
                q.push(next);
                visited[next] = true;
            }
                   
        }
        depth++;
    }

    cout << ans;
}

void Input() {
    int v1, v2;
    cin >> N >> M >> R;

    graph.resize(N + 1);
    visited.resize(N + 1, false);
    
    for(int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}