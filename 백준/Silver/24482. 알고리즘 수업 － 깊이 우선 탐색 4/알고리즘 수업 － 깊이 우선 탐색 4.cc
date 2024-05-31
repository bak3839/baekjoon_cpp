#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<int> ans;
vector<int> visit;
vector<vector<int>> graph;

void dfs(int x, int depth) {
    visit[x] = true;
    ans[x] = depth;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (ans[next] != -1 || visit[next]) continue;

        dfs(next, depth + 1);
    }
}

void Solution() {
    dfs(R, 0);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << "\n";
}

void Input() {
    int s, e;
    cin >> N >> M >> R;

    graph.resize(N + 1);
    ans.resize(N + 1, -1);
    visit.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    ans[R] = 0;
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