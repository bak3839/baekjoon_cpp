#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<vector<int>> graph;

void dfs(int x, int prev, int depth) {
    int sum = 0;

    if (graph[x].size() == 1 && x != 1) {
        ans += depth;
        return;
    }
    
    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (next == prev) continue;
        dfs(next, x, depth + 1);
    }
}

void Solution() {
    dfs(1, 0, 0);

    if (ans % 2) cout << "Yes";
    else cout << "No";
}

void Input() {
    int v1, v2;
    cin >> N;

    graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
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
