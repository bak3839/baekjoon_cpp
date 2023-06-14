#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, sum_B, sum_W;
vector<vector<char>> map;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void bfs(int a, int b) {
    queue<pii> q;
    q.push({ a, b });
    
    char ch = map[a][b];
    map[a][b] = '.';

    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] != ch) continue;

            q.push({ nx, ny });
            map[nx][ny] = '.';
            cnt++;         
        }
    }

    if (ch == 'W') sum_W += cnt * cnt;
    else sum_B += cnt * cnt;
}

void Solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != '.') bfs(i, j);
        }
    }
    cout << sum_W << " " << sum_B;
}

void Input() {
    string s;
    cin >> M >> N;
    map.resize(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        cin >> s;

        for (int j = 0; j < M; j++) 
            map[i][j] = s[j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}