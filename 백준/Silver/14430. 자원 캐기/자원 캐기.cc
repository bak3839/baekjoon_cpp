#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> DP;

void Solution() {
    int ans = 0;

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= M;j++) {
            DP[i][j] = max(DP[i - 1][j] + DP[i][j], DP[i][j - 1] + DP[i][j]);
            ans = max(ans, DP[i][j]);
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;
    DP.resize(N + 1, vector<int>(M + 1, 0));

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= M;j++)
            cin >> DP[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}