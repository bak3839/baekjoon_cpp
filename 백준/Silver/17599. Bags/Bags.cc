#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, ans = 0;;
    map<int, int> m;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;

        if (m.find(a) != m.end()) continue;

        ans++;
        m[a]++;
    }

    cout << ans;
    return 0;
}
