#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ans, cnt;
int N, M, R;
vector<bool> visit;
vector<vector<int>> graph;

void dfs(int x, long long depth) {
    cnt++;
    visit[x] = true;

    ans += (cnt * depth);

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visit[next]) continue;

        dfs(next, depth + 1);
    }
}

void Solution() {
    dfs(R, 0);

    cout << ans;
}

void Input() {
    int u, v;
    cin >> N >> M >> R;

    graph.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end(), greater<int>());
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