#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, T;
vector<int> DP;
vector<pii> cost;

void Solution() {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        int d = cost[i].first;
        int m = cost[i].second;
        sum += m;

        for (int j = T; j >= d; j--)
            DP[j] = max(DP[j], DP[j - d] + m);
    }

    cout << sum - DP[T];
}

void Input() {
    cin >> N >> T;

    cost.resize(N);
    DP.resize(T + 1, 0);

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
