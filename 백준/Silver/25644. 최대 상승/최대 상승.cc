#include <bits/stdc++.h>

using namespace std;

int N, a[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> a[i];

    int minVal = 1000000001, ans = 0;

    for (int i = 0; i < N; i++) {
        if (minVal > a[i]) minVal = a[i];
        else ans = max(ans, a[i] - minVal);
    }

    cout << ans;
    return 0;
}