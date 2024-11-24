#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

typedef struct {
    int x1, y1, x2, y2;
}Coin;

bool finish = true;
int N, M, ans = 1;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<pii> loc;
vector<string> map;
vector<vector<bool>> checked;
vector<vector<int>> CoinLocNum;

bool FallOfBoard(int x, int y) {
    return (x < 0 || y < 0 || x >= N || y >= M);
}

void IsWall(int x, int y, int* nx, int* ny) {
    if (map[*nx][*ny] == '#') {
        *nx = x;
        *ny = y;
    }
}

void BFS() {
    bool f1, f2;
    int x1, x2, y1, y2, nx1, nx2, ny1, ny2, c1, c2;

    x1 = loc[0].first, y1 = loc[0].second;
    x2 = loc[1].first, y2 = loc[1].second;
    c1 = CoinLocNum[x1][y1];
    c2 = CoinLocNum[x2][y2];

    queue<Coin> q;
    q.push({ x1, y1, x2, y2 });
    checked[c1][c2] = true;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            x1 = q.front().x1, y1 = q.front().y1;
            x2 = q.front().x2, y2 = q.front().y2;
            q.pop();

            for (int i = 0; i < 4; i++) {
                nx1 = x1 + mv[i][0], ny1 = y1 + mv[i][1];
                nx2 = x2 + mv[i][0], ny2 = y2 + mv[i][1];
                f1 = FallOfBoard(nx1, ny1);
                f2 = FallOfBoard(nx2, ny2);

                if ((f1 && !f2) || (!f1 && f2)) return;
                if (f1 && f2) continue;

                IsWall(x1, y1, &nx1, &ny1);
                IsWall(x2, y2, &nx2, &ny2);

                c1 = CoinLocNum[nx1][ny1];
                c2 = CoinLocNum[nx2][ny2];
                
                if (checked[c1][c2]) continue;

                checked[c1][c2] = true;
                q.push({ nx1, ny1, nx2, ny2 });
            }
        }

        ans++;

        if (ans == 11) break;
    }

    ans = -1;
}


void Solution() {
    BFS();
    cout << ans;
}

void InsertCoinNum(vector<vector<int>>& C) {
    int num = 0;

    C.resize(N, vector<int>(M));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C[i][j] = num++;
        }
    }
}

void Input() {
    int size = 0;
    cin >> N >> M;

    size = N * M;

    map.resize(N);
    checked.resize(size, vector<bool>(size, false));

    for (int i = 0; i < N; i++) {
        cin >> map[i];

        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'o')
                loc.push_back({ i, j });
        }
    }
        
    InsertCoinNum(CoinLocNum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}