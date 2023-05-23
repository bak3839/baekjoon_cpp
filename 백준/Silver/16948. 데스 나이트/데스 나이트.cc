#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int x;
    int y;
    int cnt;
}Knight;

int N, r1, c1, r2, c2;
int mv[6][2] = { {-2, -1},{-2, 1},{0, -2},{0, 2},{2, -1}, {2, 1} };
vector<vector<bool>> visit;

void Solution() {
    int ans = -1;
    queue<Knight> q;
    q.push({ r1,c1,0 });
    visit[r1][c1] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if (x == r2 && y == c2) {
            ans = cnt;
            break;
        }

        for (int i = 0;i < 6;i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (!visit[nx][ny]) {
                q.push({ nx, ny, cnt + 1 });
                visit[nx][ny] = true;
            }
        }
    }
    cout << ans;
}

void Input() {
    cin >> N >> r1 >> c1 >> r2 >> c2;

    visit.resize(N, vector<bool>(N, false));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}