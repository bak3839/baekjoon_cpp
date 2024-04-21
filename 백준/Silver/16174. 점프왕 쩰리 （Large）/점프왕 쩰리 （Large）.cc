#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N;
vector<vector<int>> map;
vector<vector<bool>> visit;

void Solution() {
    queue<pii> q;
    q.push({ 0, 0 });
    visit[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int jump = map[x][y];

        if (jump == -1) {
            cout << "HaruHaru";
            return;
        }

        for (int i = 0; i < 2; i++) {
            int nx, ny;

            if (i == 0) {
                nx = x + jump;
                ny = y;
            }
            else {
                nx = x;
                ny = y + jump;
            }

            if (nx >= N || ny >= N || visit[nx][ny]) continue;

            q.push({ nx, ny });
            visit[nx][ny] = true;
        }
    }

    cout << "Hing";
}

void Input() {
    cin >> N;

    map.resize(N, vector<int>(N));
    visit.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
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