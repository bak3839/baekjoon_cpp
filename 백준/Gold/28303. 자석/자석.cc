#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> Energy;
vector<int> Reverse;

void Solution() {
    int ans = -2000000000;
    int minNS = 2000000000, minSN = 2000000000;

    for (int i = 2; i <= N; i++) {
        int j = i - 1;

        minSN = min(minSN, Energy[j] - K * j);
        minNS = min(minNS, Reverse[j] - K * j);

        ans = max(ans, Energy[i] - K * i - minSN);
        ans = max(ans, Reverse[i] - K * i - minNS);
    }

    cout << ans;
}

void Input() {
    int e;
    cin >> N >> K;

    Energy.resize(N + 1, 0);
    Reverse.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> e;
        Energy[i] = e;
        Reverse[N - i + 1] = e;
    }       
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}