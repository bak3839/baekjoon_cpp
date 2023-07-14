#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> DP;

void Solution() {
    int sum = 0;

    for (int i = 2; i <= N; i++) {
        DP[i][0] = DP[i - 1][1];
        DP[i][9] = DP[i - 1][8];

        for (int j = 1; j <= 8; j++)
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
    }

    for (int i = 1; i <= 9; i++)
        sum = (sum + DP[N][i]) % 1000000000;

    cout << sum;
}

void Input() {
    cin >> N;
    DP.resize(N + 1, vector<int>(10, 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}