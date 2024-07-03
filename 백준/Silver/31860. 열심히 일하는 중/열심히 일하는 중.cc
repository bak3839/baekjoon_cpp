#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
priority_queue<int> pq;

void Solution() {
    int Y = 0;
    vector<int> ans;

    while (!pq.empty()) {
        int res = pq.top();
        pq.pop();

        ans.push_back(Y == 0 ? res : Y / 2 + res);
        Y = ans.back();

        res -= M;

        if (res > K) pq.push(res);
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}

void Input() {
    int n;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> n;
        pq.push(n);
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}