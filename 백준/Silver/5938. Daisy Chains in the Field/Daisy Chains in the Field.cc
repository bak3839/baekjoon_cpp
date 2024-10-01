#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cnt = 0;
vector<bool> visit;
vector<vector<int>> cow;

void dfs(int x) {
    cnt++;
    visit[x] = true;

    for (int i = 0; i < cow[x].size(); i++) {
        int next = cow[x][i];

        if (visit[next]) continue;

        dfs(next);
    }
}

void Solution() {
    dfs(1);

    if (cnt == N) {
        cout << 0;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visit[i]) continue;

        cout << i << "\n";
    }
}

void Input() {
    int v1, v2;
    cin >> N >> M;

    cow.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        
        cow[v1].push_back(v2);
        cow[v2].push_back(v1);
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