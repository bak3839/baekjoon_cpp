#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N, K;

void Solution() {
    int point, ans = 0;
    map<int, int> m;

    for (int i = 0; i < N; i++) {
        cin >> point;

        m[point]++;
    }

    vector<pii> res(m.begin(), m.end());
    sort(res.begin(), res.end(), greater<pii>());

    for (auto r : res) {
        if (ans >= K) break;
        ans += r.second;
    }

    cout << ans;
}

void Input() {
    cin >> N >> K;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}