#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N;
vector<int> S;
vector<pii> DP;

void Solution() {
    int ans = 1;
    DP[0] = {1, 1};

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (S[i] > S[j]) DP[i].first = max(DP[j].first + 1, DP[i].first);
            else if (S[i] < S[j]) DP[i].second = max(DP[j].second + 1, max(DP[i].second, DP[j].first + 1));           
        }
        ans = max(ans, max(DP[i].first, DP[i].second));
    }

    cout << ans;
}

void Input() {
    cin >> N;

    S.resize(N);
    DP.resize(N, { 1,1 });

    for (int i = 0; i < N; i++)
        cin >> S[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}