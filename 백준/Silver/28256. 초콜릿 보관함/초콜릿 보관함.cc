#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, cnt;
int mv[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<int> res;
vector<string> map;

void dfs(int x, int y) {
    cnt++;
    map[x][y] = 'X';

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3 || map[nx][ny] != 'O') continue;

        dfs(nx, ny);
    }
}

void Solution() {
    int n, a;
    vector<int> ans;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] != 'O') continue;

            dfs(i, j);
            res.push_back(cnt);
            cnt = 0;
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;

        ans.push_back(a);
    }

    if (n != res.size()) {
        cout << "0\n";
        return;
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < n; i++) {
        if (ans[i] != res[i]) {
            cout << "0\n";
            return;
        }
    }

    cout << "1\n";
}

void Input() {
    map.resize(3);

    for (int i = 0; i < 3; i++)
        cin >> map[i];
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        res.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}