#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> consulting;
vector<int> DP;

void Solution() {
    int ans = 0, prev = 0;

    for (int i = 1; i <= N; i++) {
        int t = consulting[i].first;
        int p = consulting[i].second;
        int end = t + i;
        prev = max(prev, DP[i]);

        if (end > N + 1) continue;

        DP[end] = max(DP[end], prev + p);
        ans = max(DP[end], ans);
    }

    cout << ans;
}

void Input() {
    cin >> N;
    consulting.resize(N + 1);
    DP.resize(N + 2, 0);

    for (int i = 1; i <= N;i++)
        cin >> consulting[i].first >> consulting[i].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}