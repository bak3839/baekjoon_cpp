#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, T, prev = 1;
    vector<ll> DP(1000001, 0);
    DP[1] = 1;

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = prev + 1; i <= N; i++)
            DP[i] = DP[i - 1] + (i * i);

        if (N > prev) prev = N;
        cout << DP[N] << "\n";
    }
    return 0;
}