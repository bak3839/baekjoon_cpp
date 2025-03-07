#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
vector<bool> visited;
vector<vector<int>> graph;

bool bfs() {
    int ans = 1;
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (visited[next]) continue;

            ans++;
            q.push(next);
            visited[next] = true;
        }
    }

    return (ans == N ? true : false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, s, e;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        graph.resize(N);
        visited.resize(N, false);

        for (int i = 0; i < M; i++) {
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }

        if (bfs()) cout << "Connected.\n";
        else cout << "Not connected.\n";

        graph.clear();
        visited.clear();
    }

    return 0;
}
