#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> wire;
vector<int> DP;

void Solution() {
    int ans = 1;

    for (int i = 1; i < N; i++) {
        int s = wire[i].first, e = wire[i].second;

        for (int j = i - 1; j >= 0; j--) {
            int ps = wire[j].first, pe = wire[j].second;

            if ((s < ps && e > pe) || (s > ps && e < pe)) continue;

            DP[i] = max(DP[i], DP[j] + 1);
        }
        ans = max(ans, DP[i]);
    }
    cout << N - ans;
}

void Input() {
    cin >> N;
    wire.resize(N);
    DP.resize(N, 1);

    for (int i = 0; i < N; i++)
        cin >> wire[i].first >> wire[i].second;
    sort(wire.begin(), wire.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}