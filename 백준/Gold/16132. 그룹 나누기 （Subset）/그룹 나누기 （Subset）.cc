#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N, sum;
vector<vector<ll>> DP;

void Solution() {
    int prev_sum = 0;

    if (sum % 2) {
        cout << 0;
        return;
    }
    DP[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        DP[i][0] = 1;

        for (int j = 1; j <= prev_sum + i; j++) {
            if (i > j) DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j] + DP[i - 1][j - i];
        }
        prev_sum += i;
    }

    cout << DP[N][sum / 2] / 2;
}

void Input() {
    cin >> N;

    sum = N * (N + 1) / 2;
    DP.resize(N + 1, vector<ll>(sum + 1, 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
