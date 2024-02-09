#include <iostream>
#include <vector>

using namespace std;

int R, C, K;

void Solution() {
    if (R * C < K) {
        cout << 0;
        return;
    }

    int mode = 1, x = R, y = 1;
    vector<vector<bool>> visit(R + 1, vector<bool>(C + 1, false));

    while (--K) {
        visit[x][y] = true;

        if (mode == 1) {
            if (visit[x - 1][y] || x - 1 == 0) {
                mode = 2;
                y++;
            }

            else x--;
        }

        else if (mode == 2) {
            if (y + 1 > C || visit[x][y + 1]) {
                mode = 3;
                x++;
            }

            else y++;
        }

        else if (mode == 3) {
            if (x + 1 > R || visit[x + 1][y]) {
                mode = 4;
                y--;
            }

            else x++;
        }

        else if (mode == 4) {
            if (visit[x][y - 1]) {
                mode = 1;
                x--;
            }

            else y--;
        }
    }

    cout << y << " " << R - x + 1;
}

void Input() {
    cin >> C >> R >> K;
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
