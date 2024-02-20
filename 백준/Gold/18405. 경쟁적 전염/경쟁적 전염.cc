#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, K, S, X, Y;
vector<queue<pii>> loc;
vector<vector<int>> map;

int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void Solution() {

    while (S--) {

        for (int i = 1; i <= K; i++) {
            queue<pii> q = loc[i];
            int size = q.size();

            for (int j = 0; j < size; j++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + mv[k][0];
                    int ny = y + mv[k][1];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (map[nx][ny] != 0) continue;

                    loc[i].push({nx, ny});
                    map[nx][ny] = i;
                }
            }
        }

        if (map[X - 1][Y - 1] != 0) break;
    }

    cout << map[X - 1][Y - 1];      
}

void Input() {
    cin >> N >> K;

    loc.resize(K + 1);
    map.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            loc[map[i][j]].push({ i, j });
        }
            

    cin >> S >> X >> Y;
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
