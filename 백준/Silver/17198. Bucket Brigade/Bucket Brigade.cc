#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int X, Y;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<string> map(10);

int BFS(int a, int b) {
    queue<pii> q;
    q.push({ a, b });
    map[a][b] = 'R';

    int ans = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];

                if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10 || map[nx][ny] == 'R') continue;

                if (map[nx][ny] == 'B') {
                    goto escape;
                }

                q.push({ nx, ny });
                map[nx][ny] = 'R';
            }
        }

        ans++;
    }

    escape:
    return ans;
}

void Solution() {
    cout << BFS(X, Y);
}

void Input() {
    for (int i = 0; i < 10; i++) {
        cin >> map[i];

        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'L') {
                X = i;
                Y = j;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}