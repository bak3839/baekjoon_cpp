#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<vector<long long>> DP;

void Solution() {
    DP[1][1] = 1;

    for (int i = 1;i <= N;i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) continue;
            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1] + DP[i - 1][j - 1]) % 1000000007;
        }
    }


    cout << DP[N][M];
}

void Input() {
    cin >> N >> M;

    DP.resize(N + 1, vector<long long>(M + 1, 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}