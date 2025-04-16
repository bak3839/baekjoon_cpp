#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int R, C, mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
string S[16];

int bfs(vector<pii> v) {
    int cnt = 0;
    queue<pii> q;
    for (pii p : v) {
        q.push({ p.first, p.second });
        S[p.first][p.second] = 'X';
    }

    while (q.size()) {
        int size = q.size();
        cnt++;

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];

                if (nx < 0 || ny < 0 || nx >= R || ny >= C || S[nx][ny] == 'X') continue;
                if (S[nx][ny] == 'G') return cnt;

                S[nx][ny] = 'X';
                q.push({ nx, ny });
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        vector<pii> v;
        cin >> R >> C;

        for (int i = 0; i < R; i++) {
            cin >> S[i];
            for (int j = 0; j < C; j++) {
                if (S[i][j] == 'S') {
                    v.push_back({ i, j });
                }
            }
        }
            
        int cnt = bfs(v);
        if (cnt == -1) cout << "No Exit\n";
        else cout << "Shortest Path: " << cnt << "\n";
    }

    return 0;
}