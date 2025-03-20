#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, ans = 0;
    cin >> X;

    for (int i = (1 << 6); i >= 1; i = (i >> 1)) {
        if (X == 0) break;

        if (X - i < 0) continue;

        ans++;
        X -= i;
    }

    cout << ans;
    return 0;
}
