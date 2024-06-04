#include <iostream>
#include <vector>

using namespace std;

int N, M, S, ans;
vector<bool> visited;
vector<vector<int>> graph;

void dfs(int x, int cnt) {
    visited[x] = true;
    ans++;

    for(int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if(visited[next]) continue;

        dfs(next, cnt + 1);
    }
}

void Solution() {
    dfs(S, 0);
    cout << ans - 1;
}

void Input() {
    int s, e;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 0; i < M; i++) {
        cin >> s >> e;
        graph[e].push_back(s);
    }
    cin >> S;
}

void Solve() {
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}