#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<int> ans;
vector<vector<int>> graph;

void dfs(int x, int depth) {

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (ans[next] != -1) continue;

        ans[next] = depth;
        dfs(next, depth + 1);
    }
}

void Solution() {
    ans[R] = 0;

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(R, 1);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << "\n";
}

void Input() {
    int u, v;
    cin >> N >> M >> R;

    ans.resize(N + 1, -1);
    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
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