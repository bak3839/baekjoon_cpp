#include <bits/stdc++.h>

using namespace std;

int N, c[50001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ans = 1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        ans = max(ans, ++c[n]);
    }

    cout << ans;
    return 0;
}