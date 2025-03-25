#include <bits/stdc++.h>

using namespace std;

int n, k, a[100002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int L = 0, R = k - 1, ans = 0, sum = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i < k) sum += a[i];
    }

    ans = sum;

    while(R < n) {
        sum -= a[L++];
        sum += a[++R];

        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}