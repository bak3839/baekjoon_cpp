#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
vector<vector<bool>> visited;
int mv1[6][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {0, -1} };
int mv0[6][2] = { {-1, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, -1}, {0, -1} };

int bfs() {
    int ans = 0;

    queue<pii> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (q.size()) {
        int size = q.size();
        ans++;

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 6; i++) {
                int nx = x + (x % 2 == 0 ? mv0[i][0] : mv1[i][0]);
                int ny = y + (x % 2 == 0 ? mv0[i][1] : mv1[i][1]);

                if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;
                if (nx == N - 1 && ny == M - 1) return ans;

                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, x, y;
    cin >> N >> M >> K;
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        visited[x][y] = true;
    }

    cout << bfs();
    return 0;
}
