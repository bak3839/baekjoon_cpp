#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, S, E, C, ans = 210000000;
vector<bool> visit;
vector<vector<int>> cost;

void Search(int x, int total, int maxCost) {
    if (total > C) return;

    if (x == E) {
        ans = min(ans, maxCost);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (cost[x][i] == 0 || visit[i]) continue;

        visit[i] = true;
        Search(i, total + cost[x][i], max(maxCost, cost[x][i]));
        visit[i] = false;
    }
}

void Solution() {
    Search(S, 0, 0);
    
    if (ans == 210000000) cout << -1;
    else cout << ans;
}

void Input() {
    int s, e, c;
    cin >> N >> M >> S >> E >> C;

    visit.resize(N + 1, false);
    cost.resize(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        cost[s][e] = cost[e][s] = c;
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
