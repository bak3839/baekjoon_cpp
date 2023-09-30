#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long DP[31];
    int last = 1, n;
    DP[1] = 1;

    while (1) {
        cin >> n;

        if (!n) break;

        for (int i = last + 1; i <= n; i++) {
            DP[i] = DP[i - 1] * (4 * i - 2) / (i + 1);
        }
        cout << DP[n] << "\n";
    }

    return 0;
}