#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> map;
vector<pair<int, char>> dir;

int idx_mv, idx_dir;
pair<int, int> mv[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void dir_change(char d) {
    if (idx_mv == 0)  idx_mv = (d == 'L') ? 3 : 1;

    else if (idx_mv == 1) idx_mv = (d == 'L') ? 0 : 2;

    else if (idx_mv == 2) idx_mv = (d == 'L') ? 1 : 3;

    else if (idx_mv == 3) idx_mv = (d == 'L') ? 2 : 0;
}

int Move(int N) {
    deque<pair<int, int>> d;
    d.push_back({ 1, 1 });
    int Time = 0;

    while (!d.empty()) {
        Time++;
        int x = d.front().first;
        int y = d.front().second;

        int nx = x + mv[idx_mv].first;
        int ny = y + mv[idx_mv].second;

        if (nx <= 0 || nx > N || ny <= 0 || ny > N || map[nx][ny] == 1) break;

        d.push_front({ nx, ny });
 
        if (map[nx][ny] == 0) {
            int px = d.back().first;
            int py = d.back().second;
            d.pop_back();

            map[px][py] = 0;
        }
        map[nx][ny] = 1;

        if (idx_dir < dir.size() && dir[idx_dir].first == Time) {
            dir_change(dir[idx_dir].second);
            idx_dir++;
        }
    }

    return Time;
}

void Input(int N, int K) {
    map.resize(N + 1, vector<int>(N + 1, 0));

    char ch;
    int x, y, s, n;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        map[x][y] = 2;
    }
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> ch;
        dir.push_back({ s, ch });
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    Input(N, K);
    cout << Move(N);
    return 0;
}