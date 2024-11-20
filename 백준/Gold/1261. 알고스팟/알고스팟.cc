#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<string> map;
vector<vector<int>> res;

typedef struct {
    int x;
    int y;
}Node;

void BFS() {
    int x, y, nx, ny;

    deque<Node> q;
    q.push_back({ 0, 0});
    res[0][0] = 0;

    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            nx = x + mv[i][0];
            ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || res[nx][ny] != -1) continue;

            if (map[nx][ny] == '0') {
                res[nx][ny] = res[x][y];
                q.push_front({ nx, ny });
            }
            else {
                res[nx][ny] = res[x][y] + 1;
                q.push_back({ nx, ny });
            }
        }
    }
}

void Solution() {
    BFS();
    cout << res[N - 1][M - 1];
}

void Input() {
    cin >> M >> N;

    map.resize(N);
    res.resize(N, vector<int>(M, -1));

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