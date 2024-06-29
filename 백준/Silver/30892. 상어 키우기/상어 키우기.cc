#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, T;
vector<int> shark;

void Solution() {
    long long ans = T;
    stack<int> s;
    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (shark[i] < T) s.push(shark[i]);
        else q.push(shark[i]);
    }

    for (int i = 0; i < K; i++) {
        if (s.empty()) break;

        ans += s.top();
        s.pop();

        while (!q.empty() && ans > q.front()) {
            s.push(q.front());
            q.pop();
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> K >> T;

    shark.resize(N);

    for (int i = 0; i < N; i++)
        cin >> shark[i];
    sort(shark.begin(), shark.end());
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