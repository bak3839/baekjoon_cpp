#include <bits/stdc++.h>
#define prev ppp

using namespace std;

int N, a[100001], prev, ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);

    prev = a[0];

    for (int i = 1; i < N; i++) {
        if (prev * 2 > a[i]) continue;

        ans++;
        prev = a[i];
    }

    cout << ans;
    return 0;
}