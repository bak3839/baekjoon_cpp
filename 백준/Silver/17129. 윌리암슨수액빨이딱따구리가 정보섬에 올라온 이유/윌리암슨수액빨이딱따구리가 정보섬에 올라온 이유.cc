#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, R, C;
int mv[4][2] = { {-1,0}, {1, 0}, {0, -1}, {0,1} };
vector<string> map;

void Solution() {
    queue<pii> q;
    q.push({ R, C });
    map[R][C] = '1';

    int size, cnt = 0;

    while (!q.empty()) {
        size = q.size();

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '1') continue;

                if (map[nx][ny] == '3' || map[nx][ny] == '4' || map[nx][ny] == '5') {
                    cout << "TAK\n" << cnt + 1;
                    return;
                }

                q.push({ nx, ny });
                map[nx][ny] = '1';
            }
        }

        cnt++;
    }

    cout << "NIE";
}

void Input() {
    bool pass = false;
    cin >> N >> M;

    map.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> map[i];

        for (int j = 0; j < M; j++) {
            if (pass) break;

            if (map[i][j] == '2') {
                R = i; C = j;
                pass = true;
            }
        }
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