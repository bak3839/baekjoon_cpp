#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;

void dfs(int x) {
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next]) return;

        dfs(next);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, cnt = 1;
    map<string, int> m;

    while (1) {
        int num = 1, ans = 0;
        string s1, s2;

        cin >> N;
        
        if (N == 0) break;

        graph.resize(N + 1);
        visited.resize(N + 1, false);
        
        for (int i = 0; i < N; i++) {
            int s, e;
            cin >> s1 >> s2;

            if (m[s1] == 0) {
                s = m[s1] = num++;
            }
            else {
                s = m[s1];
            }

            if (m[s2] == 0) {
                e = m[s2] = num++;
            }
            else {
                e = m[s2];
            }

            graph[s].push_back(e);
        }

        for (int i = 1; i <= N; i++) {
            if (visited[i]) continue;

            dfs(i);
            ans++;
        }

        cout << cnt << " " << ans << "\n";
        cnt++;

        m.clear();
        graph.clear();
        visited.clear();
    }

    return 0;
}
