#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, cnt = 0, ans = 0;
    string A, B;
    cin >> N >> A >> B;

    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) cnt++;
        else {
            if (cnt == 0) continue;

            ans++;
            cnt = 0;
        }
    }

    if (cnt != 0) ans++;
    cout << ans;

    return 0;
}
