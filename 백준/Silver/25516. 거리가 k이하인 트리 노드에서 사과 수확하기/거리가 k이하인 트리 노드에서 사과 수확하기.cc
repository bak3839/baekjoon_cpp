#include <iostream>
#include <vector>

using namespace std;

int n, k, ans;
vector<int> apple;
vector<bool> visit;
vector<vector<int>> graph;

void dfs(int x, int depth) {
    if (depth == k) return;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visit[next]) continue;

        if (apple[next]) ans++;

        visit[next] = true;
        dfs(next, depth + 1);
        visit[next] = false;
    }
}

void Solution() {
    if (apple[0]) ans++;
    visit[0] = true;
    dfs(0, 0);

    cout << ans;
}

void Input() {
    int p, c;
    cin >> n >> k;

    apple.resize(n);
    graph.resize(n);
    visit.resize(n, false);

    for (int i = 0; i < n - 1; i++) {
        cin >> p >> c;

        graph[p].push_back(c);
        graph[c].push_back(p);
    }

    for (int i = 0; i < n; i++) cin >> apple[i];
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