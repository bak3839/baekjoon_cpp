#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {

    int N, K, a, b;
    cin >> N >> K;

    vector<pii> cow1, cow2, ans;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        cow1.push_back({ a, i });
        cow2.push_back({ b, i });
    }

    sort(cow1.begin(), cow1.end(), greater<pii>());

    for (int i = 0; i < K; i++) {
        ans.push_back(cow2[cow1[i].second]);
    }

    sort(ans.begin(), ans.end(), greater<pii>());
    cout << ans[0].second + 1;
    return 0;
}