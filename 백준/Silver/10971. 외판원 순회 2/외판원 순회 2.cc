#include <iostream>
#include <vector>

using namespace std;

int N, ans = 2100000000;
vector<bool> visit;
vector<vector<int>> W;

void Search(int prev, int cnt, int sum, int start) {
    if (cnt == N) {
        if (W[prev][start] == 0) return;

        ans = min(ans, sum + W[prev][start]);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visit[i] || W[prev][i] == 0) continue;

        visit[i] = true;
        Search(i, cnt + 1, sum + W[prev][i], start);
        visit[i] = false;
    }
}

void Solution() {
    for (int i = 0; i < N; i++) {
        visit[i] = true;
        Search(i, 1, 0, i);
        visit[i] = false;
    }

    cout << ans;
}

void Input() {
    cin >> N;

    visit.resize(N, false);
    W.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];
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
