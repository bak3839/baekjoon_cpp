#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int R, C, T;
vector<vector<int>> map;
vector<vector<int>> tmp;
vector<pii> ac;

void MoveUp(int start, int end, int col) {
    for (int i = start; i < end; i++) 
        tmp[i - 1][col] = tmp[i][col];
}

void MoveDown(int start, int end, int col) {
    for (int i = start; i >= end; i--)
        tmp[i + 1][col] = tmp[i][col];
}

void MoveLeft(int row) {
    for (int i = 1; i < C; i++) 
        tmp[row][i - 1] = tmp[row][i];
}

void MoveRight(int row) {
    for (int i = C - 2; i >= 1; i--)
        tmp[row][i + 1] = tmp[row][i];
}

void AirCleanerOn() {
    pii TopStart = ac[0];
    pii BottomStart = ac[1];

    tmp[TopStart.first - 1][TopStart.second] = 0;
    tmp[BottomStart.first + 1][BottomStart.second] = 0;


    // 위
    MoveDown(TopStart.first - 2, 0, 0);
    MoveLeft(0);
    MoveUp(1, TopStart.first + 1, C - 1);
    MoveRight(TopStart.first);
    

    // 아래
    MoveUp(BottomStart.first + 2, R, 0);
    MoveLeft(R - 1);
    MoveDown(R - 2, BottomStart.first, C - 1);
    MoveRight(BottomStart.first);

    tmp[TopStart.first][TopStart.second + 1] = 0;
    tmp[BottomStart.first][BottomStart.second + 1] = 0;
}

int AirCleanerOff() {
    int ans = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == -1 || map[i][j] == 0) continue;

            ans += map[i][j];
        }     
    }

    return ans;
}

void MapCopy() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == -1) continue;

            map[i][j] = tmp[i][j];
        }

        fill(tmp[i].begin(), tmp[i].end(), 0);
    }
}

void Diffusion() {
    int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int now = map[i][j];

            if (now == 0 || now == -1) continue;

            int dust = map[i][j] / 5;
            
            for (int k = 0; k < 4; k++) {
                int nr = i + mv[k][0];
                int nc = j + mv[k][1];

                if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
                if (map[nr][nc] == -1) continue;

                map[i][j] -= dust;
                tmp[nr][nc] += dust;               
            }

            tmp[i][j] += map[i][j];
        }
    }       
}

void Solution() {
    while (T--) {
        Diffusion();
        AirCleanerOn();
        MapCopy();
    }

    cout << AirCleanerOff();
}

void Input() {
    cin >> R >> C >> T;

    map.resize(R, vector<int>(C));
    tmp.resize(R, vector<int>(C, 0));

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];

            if (map[i][j] == -1) ac.push_back({ i, j });
        }            
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
