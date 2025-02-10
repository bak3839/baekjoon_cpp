#include <bits/stdc++.h>

using namespace std;
using psi = pair<string, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string ans;
    int N, M, p, L, R, mid;
    cin >> N >> M;

    vector<psi> style(N);
    

    for (int i = 0; i < N; i++) {
        cin >> style[i].first >> style[i].second;
    }

    for (int i = 0; i < M; i++) {
        cin >> p;
        L = 0, R = N - 1;

        while (L <= R) {
            mid = (L + R) / 2;

            if (p <= style[mid].second) {
                ans = style[mid].first;
                R = mid - 1;
            }
            else L = mid + 1;
        }

        cout << ans << "\n";
    }
    return 0;
}
