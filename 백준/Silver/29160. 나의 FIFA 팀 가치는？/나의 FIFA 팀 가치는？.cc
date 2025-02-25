#include <bits/stdc++.h>

using namespace std;

bool checked[12];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, p, w, ans = 0;
    cin >> N >> K;

    vector<priority_queue<int>> pq(12);

    for (int i = 0; i < N; i++) {
        cin >> p >> w;
        pq[p].push(w);
    }

    while (K--) {
        for (int i = 1; i <= 11; i++) {
            if (pq[i].empty()) continue;

            w = pq[i].top();
            pq[i].pop();
            w--;

            if (w == 0) continue;
            pq[i].push(w);
        }
    }

    for (int i = 1; i <= 11; i++) {
        if (pq[i].empty()) continue;

        ans += pq[i].top();
    }

    cout << ans;
    return 0;
}
