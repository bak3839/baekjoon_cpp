#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M;
int mv[2][2] = { {1, 0}, {0, 1} };
vector<vector<char>> map;

void Solution() {
    queue<pii> q;
    q.push({ 0, 0 });
    map[0][0] = '0';

    bool arrive = false;

    if (N == 1 && M == 1) {
        arrive = true;
        goto label;
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        

        for (int i = 0; i < 2; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx >= M || ny >= N || map[nx][ny] == '0') continue;

            if (nx == M - 1 && ny == N - 1) {
                arrive = true;
                goto label;
            }

            q.push({ nx,ny });
            map[nx][ny] = '0';
        }
    }

label:

    cout << (arrive ? "Yes" : "No");
}

void Input() {
    cin >> N >> M;

    map.resize(M, vector<char>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }    
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}