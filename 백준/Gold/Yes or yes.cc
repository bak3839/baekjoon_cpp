#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> fan;
vector<bool> visit;
vector<vector<int>> graph;

bool dfs(int x) {
    if (graph[x].empty()) return true;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visit[next] || fan[next]) continue;

        visit[next] = true;
        if (dfs(next)) return true;
    }

    return false;
}

void Solution() {
    if (!fan[1]) {
        if (dfs(1)) cout << "yes";
        else cout << "Yes";
    }
    else cout << "Yes";
}

void Input() {
    int u, v, S, s;
    cin >> N >> M;

    graph.resize(N + 1);
    fan.resize(N + 1, false);
    visit.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    cin >> S;

    for (int i = 0; i < S; i++) {
        cin >> s;
        fan[s] = true;
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
