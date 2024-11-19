#include <iostream>
#include <vector>

using namespace std;

int N, M, sx, sy;
int mv[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

char start;
bool cycle = false;
vector<string> map;

void DFS(int x, int y, int d) {
    char ch = map[x][y];
    map[x][y] = '.';

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (i == 3 && i - d <= 1 && sx == nx && sy == ny) {
            cycle = true;
            return;
        }

        if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '.' || map[nx][ny] != start) continue;

        DFS(nx, ny, i);

        if (cycle) return;
    }

    map[x][y] = ch;
    return;
}

void Solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            start = map[i][j];
            sx = i; sy = j;

            DFS(i, j, 0);

            if (cycle) {
                cout << "Yes";
                return;
            }
        }
    }

    cout << "No";
}

void Input() {
    cin >> N >> M;

    map.resize(N);

    for (int i = 0; i < N; i++)
        cin >> map[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}