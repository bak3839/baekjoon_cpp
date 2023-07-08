#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, T, prev = 4;
    cin >> T;

    vector<ll> DP(68);
    DP[0] = 1; DP[1] = 1; 
    DP[2] = 2; DP[3] = 4;

    while (T--) {
        cin >> N;

        for (int i = prev; i <= N; i++)
            DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3] + DP[i - 4];

        cout << DP[N] << "\n";

        if (N > prev) prev = N;
    }
    return 0;
}