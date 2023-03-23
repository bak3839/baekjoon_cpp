#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, endTime = 0, ans;
int mv1[4] = { -1,1,0,0 };
int mv2[4] = { 0,0,-1,1 };

vector<vector<char>> map;
bool visit[101][101];

void input() {
    char ch;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> ch;
            if (ch == '1') {
                map[i][j] = ch;
            }
        }
    }
}

bool bfs() {
    endTime++;
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visit[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv1[i];
            int ny = y + mv2[i];

            if (0 > nx || 0 > ny || nx > N || ny > M || visit[nx][ny]) continue;

            if (map[nx][ny] == '1') {
                cnt++;
                map[nx][ny] = '0';
            }

            else if (map[nx][ny] == '0') {
                q.push({ nx, ny });
            }
            visit[nx][ny] = true;
        }
    }

    if (cnt == 0) {
        cout << endTime - 1 << "\n" << ans;
        return true;
    }

    ans = cnt;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    map.resize(N + 1, vector<char>(M + 1, '0'));

    input();  
    while (1) {
        if (bfs()) break;
        memset(visit, false, sizeof(visit));
    }  
    return 0;
}