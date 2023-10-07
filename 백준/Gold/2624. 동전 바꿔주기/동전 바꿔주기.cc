#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int T, K;
vector<int> DP;
vector<pii> coin;

void Solution() {
    DP[0] = 1;

    for (int i = 0; i < K; i++) {
        int p = coin[i].first;
        int n = coin[i].second;

        for (int j = T; j >= 0; j--) {
            for (int k = 1; k <= n && j - p * k >= 0; k++)
                DP[j] += DP[j - p * k];
        }
    }

    cout << DP[T] ;
}

void Input() {
    cin >> T >> K;

    DP.resize(T + 1, 0);
    coin.resize(K);

    for (int i = 0; i < K; i++)
        cin >> coin[i].first >> coin[i].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
