#include <bits/stdc++.h>

using namespace std;

int N, a[100001], ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);

    int L = 0, R = N - 1, cnt = 0, prev = 0;

    while (cnt < N) {
        if (cnt % 2) {
            prev = a[L++];
        }
        else {
            ans += a[R--] - prev;
        }

        cnt++;
    }

    cout << ans;
    return 0;
}