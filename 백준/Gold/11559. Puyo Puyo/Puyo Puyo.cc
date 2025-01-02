#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

vector<string> v(12);
bool visited[12][6];
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void move(int x, int y) {
    if (x < 0 || v[x][y] == '.') return;

    v[x + 1][y] = v[x][y];
    v[x][y] = '.';
    move(x - 1, y);
}

void explo(vector<pii> res) {
    for (pii p : res) {
        int x = p.first, y = p.second;
        v[x][y] = '.';
        move(x - 1, y);
    }
}

vector<pii> bfs(int a, int b) {   
    vector<pii> res;

    queue<pii> q;
    q.push({ a, b });
    res.push_back({ a, b });
    visited[a][b] = true;

    while (q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || v[nx][ny] == '.' || visited[nx][ny]) continue;
            if (v[a][b] != v[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
            res.push_back({ nx, ny });
        }
    }

    if (res.size() < 4) res.clear();
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0, prev = -1;
    vector<pii> res, exp;
    

    for (int i = 0; i < 12; i++)
        cin >> v[i];

    while (prev != ans) {
        prev = ans;

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (v[i][j] == '.') continue;

                res = bfs(i, j);
                exp.insert(exp.end(), res.begin(), res.end());
            }
        }

        if (!exp.empty()) {
            ans++;
            explo(exp);
            exp.clear();
        }

        memset(visited, false, sizeof(visited));
    }

    cout << ans;
    return 0;
}