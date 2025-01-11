#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n, ans = 0;
    map<int, bool> m;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> n;

            if (m[n]) ans = 1;
            m[n] = true;
        }
    }

    cout << ans;
    return 0;
}