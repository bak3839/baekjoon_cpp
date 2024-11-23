#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N, M, total, ans = 2500001;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<int> num;
vector<pii> virus;
vector<vector<int>> map;
vector<vector<bool>> visited;



void BFS() {
    int size, x, y, nx, ny, v = 0, res = 0;
    queue<pii> q;

    for (auto n : num) {
        x = virus[n].first;
        y = virus[n].second;

        q.push({ x, y });
        visited[x][y] = true;
    }

    while (!q.empty()) {
        size = q.size();

        while (size--) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                nx = x + mv[i][0];
                ny = y + mv[i][1];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] || map[nx][ny] == 1) continue;

                visited[nx][ny] = true;
                q.push({ nx, ny });
                v++;
            }
        }

        res++;
    }

    for (auto& row : visited) {
        fill(row.begin(), row.end(), false);
    }

    if (v == total) ans = min(ans, res - 1);
}

void ChoiceVirus(int n) {
    if (num.size() == M) {
        BFS();
        return;
    }

    for (int i = n; i < virus.size(); i++) {
        int x = virus[i].first;
        int y = virus[i].second;

        num.push_back(i);
        ChoiceVirus(i + 1);
        num.pop_back();
    }
}

void Solution() {
    ChoiceVirus(0);

    if (ans == 2500001) cout << -1;
    else cout << ans;
}

void Input() {
    cin >> N >> M;

    total = (N * N) - M;
    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1)
                total--;

            else if (map[i][j] == 2)
                virus.push_back({ i, j });
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