#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;
    int N, M, t, ans = 0, index = 0;
    cin >> N >> M;

    vector<int> time(N);

    for (int i = 0; i < N; i++) 
        cin >> time[i];
    sort(time.begin(), time.end(), greater<int>());

    while (index < N) {
        if (pq.size() < M) {
            pq.push(time[index++]);
            continue;
        }

        t = pq.top();
        pq.pop();
        pq.push(t + time[index++]);
    }

    while (!pq.empty()) {
        ans = pq.top();
        pq.pop();
    }

    cout << ans;
    return 0;
}
