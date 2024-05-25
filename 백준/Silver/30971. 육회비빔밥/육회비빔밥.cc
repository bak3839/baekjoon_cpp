#include <iostream>
#include <vector>

using namespace std;

int N, K, ans;
vector<bool> visit;
vector<vector<int>> food;

void Search(int res, int A, int C, int cnt) {
    if (cnt == N) {
        ans = max(ans, res);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visit[i] || C * food[2][i] > K) continue;

        visit[i] = true;
        Search(res + (A * food[1][i]), food[0][i], food[2][i], cnt + 1);
        visit[i] = false;
    }
}

void Solution() {
    for (int i = 0; i < N; i++) {
        visit[i] = true;
        Search(0, food[0][i], food[2][i], 1);
        visit[i] = false;
    }

    if (ans == 0) cout << -1;
    else cout << ans;
}

void Input() {
    cin >> N >> K;

    visit.resize(N, false);
    food.resize(3, vector<int>(N));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            cin >> food[i][j];
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