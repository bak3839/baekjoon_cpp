#include <bits/stdc++.h>
#define prev ddd

using namespace std;

int N, v[500001], ans = 1, prev = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = N - 2; i >= 0; i--) {
        if (prev + 1 <= v[i]) {
            ans += prev + 1;
            prev++;
        }
        else {
            ans += v[i];
            prev = v[i];
        }
    }

    cout << ans;
    return 0;
}