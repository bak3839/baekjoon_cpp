#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<string> map;
vector<vector<int>> cnt;

int CountBomb(int r, int c) {
    int res = 0;
    int mv[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

    for (int i = 0; i < 8; i++) {
        int nr = r + mv[i][0];
        int nc = c + mv[i][1];

        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

        if (map[nr][nc] == '*') res++;
    }

    return res;
}

void Solution() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == '*') {
                cout << "*";
                continue;
            }

            cout << CountBomb(i, j);
        }
        cout << "\n";
    }
}

void Input() {
    while (1) {
        cin >> R >> C;

        if (R == 0 && C == 0) break;

        map.resize(R);
        cnt.resize(R, vector<int>(C, 0));

        for (int i = 0; i < R; i++)
            cin >> map[i];

        Solution();
        map.clear();
        cnt.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    return 0;
}