#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> hole;

void Solution() {
    int L = 0, R = 0, sum = 0, ans = 0;

    while (R < N) {
        if (sum + hole[R] <= K) {
            sum += hole[R++];
            ans = max(ans, sum);
        }

        else {
            sum -= hole[L++];
        }

        if (L == R && hole[R] > K) {
            L++; R++;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> K;

    hole.resize(N);

    for (int i = 0; i < N; i++)
        cin >> hole[i];
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