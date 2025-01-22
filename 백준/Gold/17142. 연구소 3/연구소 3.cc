#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M, total, ans = 1000000;
int A[50][50];
bool visited[50][50];
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<pii> v, on;

void bfs() {
    queue<pii> q;

    for (pii p : on) {
        q.push(p);
        visited[p.first][p.second] = true;
    }

    int size, x, y, nx, ny, res = 0, cnt = 0;

    while (q.size()) {
        size = q.size();

        while (size--) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                nx = x + mv[i][0];
                ny = y + mv[i][1];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (visited[nx][ny] || A[nx][ny] == 1) continue;

                if(A[nx][ny] == 0) cnt++;

                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
        }

        res++;
        if (cnt == total) break;
    }

    if(total == cnt) ans = min(ans, res);
    
    memset(visited, false, sizeof(visited));
}

void virusOn(int x, int cnt) {
    if (cnt == M) {
        bfs();
        return;
    }

    for (int i = x; i < v.size(); i++) {
        on.push_back(v[i]);
        virusOn(i + 1, cnt + 1);
        on.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    total = N * N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];

            if (A[i][j] == 1) total--;
            else if (A[i][j] == 2) {
                v.push_back({ i, j });
                total--;
            }
        }
    }

    if (total != 0) virusOn(0, 0);
    else ans = 0;

    if (ans == 1000000) cout << -1;
    else cout << ans;
    
    return 0;
}