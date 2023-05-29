#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int T;
ll DP[65][10];

void Solution() {
    int prev = 1, n;

    for (int i = 0; i <= 9; i++)
        DP[1][i] = i + 1;

    while (T--) {
        cin >> n;

        if (prev < n) {
            for (int j = prev + 1; j <= n; j++) {
                DP[j][0] = 1;
                for (int i = 1; i <= 9; i++) DP[j][i] = DP[j - 1][i] + DP[j][i - 1];
            }
            prev = n;
        }

        cout << DP[n][9] << "\n";
    }
}

void Input() {
    cin >> T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}