#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int R, C;
int map[5][5];
int mv[4][2] = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };

void Solution() {
    int ans = 0;
    queue<pii> q;
    q.push({ R, C });
    map[R][C] = -1;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + mv[i][0];
                int nc = c + mv[i][1];

                if (nr < 0 || nc < 0 || nr > 4 || nc > 4 || map[nr][nc] == -1) continue;

                if (map[nr][nc] == 1) {
                    cout << ans + 1;
                    return;
                }

                q.push({ nr, nc });
                map[nr][nc] = -1;
            }
        }

        ans++;
    }

    cout << -1;
}

void Input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];
    }

    cin >> R >> C;
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