#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> done;

void Solution() {
    int sx, sy, ex, ey, ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> sx >> sy >> ex >> ey;

        for (int x = sx; x <= ex; x++)
            for (int y = sy; y <= ey; y++)
                done[x][y]++;
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (done[i][j] > M) ans++;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    done.resize(101, vector<int>(101, 0));
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
