#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, s, e, ans;
    cin >> N >> M;

    ans = N;
    vector<bool> wall(N + 1, true);

    for (int i = 0; i < M; i++) {
        cin >> s >> e;

        for (int j = s; j < e; j++) {
            if (!wall[j]) continue;

            wall[j] = false;
            ans--;
        }
    }

    cout << ans;
    return 0;
}