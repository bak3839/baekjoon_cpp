#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x; int y; int cnt;
}Node;

int N;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<string> mat;
vector<vector<int>> ans;

void Bfs() {
    queue<Node> q;
    q.push({ 0, 0, 0 });
    ans[0][0] = 0;

    int x, y, nx, ny, cnt, res;

    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        cnt = q.front().cnt;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + mv[i][0];
            ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            res = cnt + (mat[nx][ny] == '0' ? 1 : 0);

            if (ans[nx][ny] <= res) continue;
           
            q.push({ nx, ny, res });
            ans[nx][ny] = res;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    mat.resize(N);
    ans.resize(N, vector<int>(N, 100000));

    for (int i = 0; i < N; i++)
        cin >> mat[i];

    Bfs();

    cout << ans[N - 1][N - 1];
    return 0;
}