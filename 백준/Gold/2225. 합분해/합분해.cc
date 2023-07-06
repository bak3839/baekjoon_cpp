#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N, K;
vector<vector<ll>> DP;

void Solution() { 
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j++)
            DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000000;
    }

    cout << DP[K][N] % 1000000000;
}

void Input() {
    cin >> N >> K;

    DP.resize(K + 1, vector<ll>(N + 1, 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}