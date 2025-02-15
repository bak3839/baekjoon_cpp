#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, M, L = 1, R = 1, mid, ans = -1, cnt;
    cin >> N >> K >> M;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];

        if (v[i] <= K || v[i] == 2 * K) v[i] = 0;
        else {
            if (v[i] > 2 * K) v[i] -= 2 * K;
            else v[i] -= K;
        }
        R = max(R, v[i]);
    }    

    while (L <= R) {
        cnt = 0;
        mid = (L + R) / 2;

        for (int i = 0; i < N; i++) {
            cnt += v[i] / mid;
        }

        if (cnt >= M) {
            L = mid + 1;
            ans = mid;
        }
        else R = mid - 1;
    }

    cout << ans;
    return 0;
}
