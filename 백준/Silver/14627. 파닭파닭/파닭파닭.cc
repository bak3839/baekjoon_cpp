#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mid, cnt, mod, ans = 0, S, C, minVal = 1000000001, L, R, sum = 0;
    cin >> S >> C;

    vector<long long> onion(S);

    for (int i = 0; i < S; i++) {
        cin >> onion[i];
        sum += onion[i];
    }
        
    L = 1;
    R = 1000000000;

    while (L <= R) {
        cnt = 0; mod = 0;
        mid = (L + R) / 2;

        for (int i = 0; i < S; i++) {
            cnt += onion[i] / mid;
        }

        if (cnt >= C) {
            L = mid + 1;
            ans = max(mid, ans);
        }
        else R = mid - 1;
    }

    cout << sum - ans * C;
    return 0;
}
