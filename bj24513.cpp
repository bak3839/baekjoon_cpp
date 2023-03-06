#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> map;
vector<vector<bool>> pre;
queue<pii> q1, q2;
int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0, -1, 1 };
int virus[4];
int N, M, size1, size2;

void move_virus1() {
    int cnt = 0;

    for (int j = 0; j < size1; j++) {
        int x = q1.front().first;
        int y = q1.front().second;
        q1.pop();

        if (map[x][y] == 3) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + mv1[i];
            int ny = y + mv2[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] != 0) continue;

            q1.push({ nx, ny });
            map[nx][ny] = 1;
            pre[nx][ny] = true;
            virus[1]++;
            cnt++;
        }
    }
    size1 = cnt;
}

void move_virus2() {
    int cnt = 0;

    for (int j = 0; j < size2; j++) {
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv1[i];
            int ny = y + mv2[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || (map[nx][ny] != 1 && map[nx][ny] != 0)) continue;
            if (!pre[nx][ny] && map[nx][ny] == 1) continue;

            if (pre[nx][ny]) {
                virus[1]--; virus[3]++;
                map[nx][ny] = 3;
                continue;
            }

            q2.push({ nx, ny });
            map[nx][ny] = 2;
            virus[2]++;
            cnt++;
        }
    }
    pre.clear();
    pre.resize(N, vector<bool>(M, false));
    size2 = cnt;
}

void solution() {
    while (1) {
        bool pass1 = true;
        bool pass2 = true;

        if (0 < size1) {
            move_virus1();
            pass1 = false;
        }
        if (0 < size2) {
            move_virus2();
            pass2 = false;
        }
   
        if (pass1 && pass2) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    map.resize(N, vector<int>(M));
    pre.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) q1.push({ i, j });
            else if (map[i][j] == 2) q2.push({ i, j });
        }
    }
    virus[1]++; virus[2]++;
    size1 = 1; size2 = 1;
    solution();

    for (int i = 1; i <= 3; i++) cout << virus[i] << " ";
}