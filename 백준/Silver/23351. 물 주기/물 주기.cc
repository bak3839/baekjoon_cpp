#include <bits/stdc++.h>

using namespace std;

int N, K, A, B, last, a[101];

bool check() {
    for (int i = 0; i < N; i++) {
        if (a[i] - 1 <= 0) return false;
        a[i] -= 1;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    cin >> N >> K >> A >> B;

    for (int i = 0; i < N; i++)
        a[i] = K;

    do {
        ans++;
        int cnt = A;

        while (cnt--) {
            if (last >= N) last = 0;

            a[last++] += B;
        }
    } while (check());

    cout << ans;
    return 0;
}