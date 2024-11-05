#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

bool pass = false;
int N, M, ans = 0;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<string> map;
vector<vector<bool>> visit;

bool BFS() {
    queue<pii> q;
    q.push({ 0, 0 });
    visit[0][0] = true;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            int cnt = map[x][y] - '0';
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + (mv[i][0] * cnt);
                int ny = y + (mv[i][1] * cnt);

                if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]) continue;

                if (nx == N - 1 && ny == M - 1) return true;

                q.push({ nx, ny });
                visit[nx][ny] = true;
            }
        }

        ans++;
    }
    return false;
}

void Solution() {
    if (BFS()) cout << ans + 1;
    else cout << "IMPOSSIBLE";
}

void Input() {
    cin >> N >> M;

    map.resize(N);
    visit.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
        cin >> map[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}