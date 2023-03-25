#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> visit;
vector<vector<int>> graph;

void input(int N, int M) {
    int v1, v2;
    for (int i = 0;i < M;i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
}

bool dfs(int n, int cnt) {
    if (cnt == 5) return true;

    bool pass = false;
    visit[n] = true;

    for (int i = 0;i < graph[n].size();i++) {
        int next = graph[n][i];
        if (!visit[next]) pass = dfs(next, cnt + 1);
        if (pass) return true;
    }

    visit[n] = false;
    return false;
}

int solve(int N) {
    bool pass = false;

    for (int i = 0;i < N;i++) {
        pass = dfs(i, 1);
        if (pass) return 1;
        else fill(visit.begin(), visit.end(), false);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    visit.resize(N);
    graph.resize(N);
    input(N, M);
    if (solve(N)) cout << 1;
    else cout << 0;
    return 0;
}