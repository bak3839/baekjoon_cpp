#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, R;
vector<int> ans;
vector<bool> visited;
vector<vector<int>> graph;

void Solution() {
    queue<int> q;
    q.push(R);
    visited[R] = true;
    
    int depth = 0;

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            int n = q.front();
            q.pop();
            ans[n] = depth;

            for(int i = 0; i < graph[n].size(); i++) {
                int next = graph[n][i];

                if(visited[next]) continue;

                q.push(next);
                visited[next] = true;
            }
        }
        depth++;
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}

void Input() {
    int u, v;
    cin >> N >> M >> R;

    ans.resize(N + 1, -1);
    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 0;i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
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