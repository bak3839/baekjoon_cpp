#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int C, N;
vector<pii> cost;
vector<int> DP;

void Solution() {
    int ans = 2100000000;

    for (int i = 0; i < N; i++) {
        int c = cost[i].first;
        int p = cost[i].second;

        DP[p] = min(DP[p], c);

        for (int j = p + 1; j <= 1100; j++) {
            DP[j] = min(DP[j], DP[j - p] + c);
        }
    }
    
    for (int i = C; i <= 1100; i++)
        ans = min(ans, DP[i]);
    cout << ans;
}

void Input() {
    cin >> C >> N;

    cost.resize(N);
    DP.resize(1101, 2100000000);

    for (int i = 0; i < N; i++)
        cin >> cost[i].first >> cost[i].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
