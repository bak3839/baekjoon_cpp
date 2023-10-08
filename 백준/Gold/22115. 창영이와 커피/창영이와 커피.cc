#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> DP;
vector<int> coffee;

void Solution() {
    DP[0] = 0;

    for (int i = 0; i < N; i++) {
        int c = coffee[i];

        for (int j = K; j >= c; j--) {
            DP[j] = min(DP[j], DP[j - c] + 1);
        }
    }

    if (DP[K] == 100001) cout << -1;
    else cout << DP[K];
}

void Input() {
    cin >> N >> K;

    coffee.resize(N);
    DP.resize(K + 1, 100001);

    for (int i = 0; i < N; i++)
        cin >> coffee[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
