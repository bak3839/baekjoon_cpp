#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n[8] = { 7,6,5,4,3,2,1,0 };
int mv[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-1, 2}, {1, 2} };
vector<vector<bool>> visit;

int sx, sy, ex, ey;

void BFS() {
    int ans = 0;

    queue<pii> q;
    q.push({ sx, sy });
    visit[sx][sy] = true;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];

                if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || visit[nx][ny]) continue;

                if (nx == ex && ny == ey) {
                    cout << ans + 1;
                    return;
                }

                visit[nx][ny] = true;
                q.push({ nx, ny });
            }
        }

        ans++;
    }
}

void Solution() {
    if (sx == ex && sy == ey) {
        cout << 0;
        return;
    }

    BFS();
}

void Input() {
    string start, end;

    cin >> start >> end;
    sx = n[start[1] - '1']; sy = start[0] - 'a';
    ex = n[end[1] - '1']; ey = end[0] - 'a';

    visit.resize(8, vector<bool>(8, false));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}