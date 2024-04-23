#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, T, ans;
vector<vector<int>> num;

void Search(int x, int y) {
    vector<int> res;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            res.push_back(num[i][j]);
        }
    }

    sort(res.begin(), res.end());

    if (res[4] >= T) ans++;
}

void Solution() {
    for (int i = 1; i < R - 1; i++) {
        for (int j = 1; j < C - 1; j++) {
            Search(i, j);
        }
    }

    cout << ans;
}

void Input() {
    cin >> R >> C;

    num.resize(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> num[i][j];
        }
    }

    cin >> T;
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