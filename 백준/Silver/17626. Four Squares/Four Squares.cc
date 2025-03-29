#include <bits/stdc++.h>

using namespace std;

int N, n, ans, dp[50004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        int n = 500004;

        for (int j = 1; j * j <= i; j++) {
            int temp = i - j * j;
            n = min(n, dp[temp]);
        }

        dp[i] = n + 1;
    }

    cout << dp[N];
    return 0;
}