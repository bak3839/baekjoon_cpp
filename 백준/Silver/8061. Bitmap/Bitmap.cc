#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

bool pass = false;
int N, M;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<string> map;
vector<vector<int>> ans;

queue<pii> q;

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int cnt = ans[x][y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '1' || ans[nx][ny] != 0) continue;

            
            ans[nx][ny] = cnt + 1;
            q.push({ nx, ny });
        }
    }
}

void Solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '0') continue;

            q.push({ i, j });
        }
    }

    BFS();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

void Input() {
    cin >> N >> M;

    map.resize(N);
    ans.resize(N, vector<int>(M, 0));

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