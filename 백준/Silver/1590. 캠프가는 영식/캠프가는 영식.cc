#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T, S, I, C, L, R, mid, ans = 2000000000;
    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        cin >> S >> I >> C;
        vector<int> bus(C);
        bus[0] = S;

        for (int j = 1; j < C; j++)
            bus[j] = bus[j - 1] + I;

        L = 0; R = C - 1;

        while (L <= R) {
            mid = (L + R) / 2;

            if (bus[mid] - T >= 0) {
                ans = min(ans, bus[mid] - T);
                R = mid - 1;
            }
            else L = mid + 1;
        }
    }

    if (ans == 2000000000) cout << -1;
    else cout << ans;
    return 0;
}
