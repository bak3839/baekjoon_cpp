#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int ans = 2100000000;
char map[3][3], target[3][3];
bool check[3][3];

bool CompareMap() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] != target[i][j])
                return false;
        }
    }

    return true;
}

void Change(int x, int y) {
    int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    map[x][y] = map[x][y] == '*' ? '.' : '*';

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;

        map[nx][ny] = map[nx][ny] == '*' ? '.' : '*';
    }
}

void Search(int x, int y, int cnt) {
    if (cnt >= ans) return;

    if (CompareMap()) {
        ans = min(ans, cnt);
        return;
    }

    Change(x, y);

    if (CompareMap()) {
        Change(x, y);
        ans = min(ans, cnt + 1);
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (check[i][j]) continue;

            check[i][j] = true;
            Search(i, j, cnt + 1);
            check[i][j] = false;
        }
    }  

    Change(x, y);
}

void Solution() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            check[i][j] = true;
            Search(i, j, 0);
            check[i][j] = false;
        }
    }

    cout << ans << "\n";
    ans = 2100000000;
}

void Input() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> target[i][j];

    memset(&map[0][0], '.', 9);
    memset(&check[0][0], false, 9);
}

void Solve() {
    int P;
    cin >> P;

    while (P--) {
        Input();
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
