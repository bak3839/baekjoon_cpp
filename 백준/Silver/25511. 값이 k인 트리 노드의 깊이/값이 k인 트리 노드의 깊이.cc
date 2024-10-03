#include <iostream>
#include <vector>

using namespace std;

int N, K, target, ans;
vector<bool> visit;
vector<vector<int>> graph;

bool dfs(int x, int depth) {
    visit[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visit[next]) continue;

        if (next == target) {
            ans = depth + 1;
            return true;
        }

        if (dfs(next, depth + 1)) return true;
    }

    return false;
}

void Solution() {
    dfs(0, 0);

    cout << ans;
}

void Input() {
    int v1, v2, n;
    cin >> N >> K;

    graph.resize(N);
    visit.resize(N, false);

    for (int i = 0; i < N - 1; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i = 0; i < N; i++) {
        cin >> n;

        if (n == K) target = i;
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}