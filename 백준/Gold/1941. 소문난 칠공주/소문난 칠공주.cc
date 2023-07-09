#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int ans, dasom, total, cnt;
char map[5][5];
bool visit[5][5], check[5][5];
int mv[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
pii princess;

void dfs(int x, int y) {
    cnt++;

    if (cnt == 7) {
        ans++;
        return;
    }

    visit[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (visit[nx][ny] || !check[nx][ny]) continue;
        
        dfs(nx, ny);
    }
}

void Combination(int x, int y) {
    int tmp = y + 1;

    if (total == 7) {
        cnt = 0;
        if (dasom >= 4) {
            dfs(princess.first, princess.second);
            fill(&visit[0][0], &visit[4][5], false);
        }
        return;
    }

    for (int i = x; i < 5; i++) {
        for (int j = tmp; j < 5; j++) {
            if (map[i][j] == 'S') dasom++;
            total++;
            check[i][j] = true;            

            Combination(i, j);

            if (map[i][j] == 'S') dasom--;
            total--;
            check[i][j] = false;
        }
        tmp = 0;
    }
}

void Solution() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == 'S') dasom++;
            total++;
            check[i][j] = true;
            princess = { i, j };
            
            Combination(i, j);

            dasom = 0;
            total = 0;
            check[i][j] = false;
        }           
    }

    cout << ans;
}

void Input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}