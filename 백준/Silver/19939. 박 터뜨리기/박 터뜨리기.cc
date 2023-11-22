#include <iostream>
#include <vector>

using namespace std;

int N, K;

void Solution() {
    int res = K * (K + 1) / 2;

    if (N < res) {
        cout << -1;
        return;
    }

    int rest = N - res;

    cout << (K - 1) + (rest % K ? 1 : 0);
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
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
