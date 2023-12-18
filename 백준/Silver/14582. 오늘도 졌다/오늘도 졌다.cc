#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> point;

void Solution() {
    int ulim = 0, star = 0;

    for (int i = 0; i < 9; i++) {
        ulim += point[0][i];

        if (ulim > star) break;
        star += point[1][i];
    }

    if (ulim > star) cout << "Yes";
    else cout << "No";
}

void Input() {
    point.resize(2, vector<int>(9));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 9; j++)
            cin >> point[i][j];
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
