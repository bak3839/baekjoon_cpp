#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, M, ans;
bool finish;
vector<vector<pii>> graph;
vector<bool> visit;

void dfs(int x, int target, int sum) {
    visit[x] = true;

    if (target == x) {
        ans = sum;
        finish = true;
        return;
    }

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i].first;
        int cost = graph[x][i].second;

        if (visit[next]) continue;

        dfs(next, target, sum + cost);

        if (finish) return;
    }
}

void Solution() {
    int s, e;

    for (int i = 0;i < M;i++) {
        cin >> s >> e;
        dfs(s, e, 0);
        cout << ans << "\n";

        ans = 0;
        finish = false;

        fill(visit.begin(), visit.end(), false);
    }
}

void Input() {
    int v1, v2, c;

    cin >> N >> M;

    graph.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 0;i < N - 1;i++) {
        cin >> v1 >> v2 >> c;

        graph[v1].push_back({ v2, c });
        graph[v2].push_back({ v1, c });
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
