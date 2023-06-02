#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, n, prev = 1;
    int DP[46];
    DP[0] = 1; DP[1] = 1;
    cin >> T;

    while (T--) {
        cin >> n;

        if (prev < n) {
            for (int i = prev + 1; i <= n; i++)
                DP[i] = DP[i - 1] + DP[i - 2];
        }
        cout << DP[n] << "\n";
    }
    return 0;
}