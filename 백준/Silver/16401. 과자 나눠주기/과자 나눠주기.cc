#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> snack;

void Solution() {
    int L = 1, R = snack[M - 1], mid, ans = 0, cnt;

    while (L <= R) {
        cnt = 0;
        mid = (L + R) / 2;

        for (int i = M - 1; i >= 0; i--) {
            int res = snack[i] / mid;

            if (res == 0) break;

            cnt += res;
        }

        if (cnt >= N) {
            ans = max(ans, mid);
            L = mid + 1;
        }
        else {
            R = mid - 1;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    snack.resize(M);

    for (int i = 0; i < M; i++)
        cin >> snack[i];
    sort(snack.begin(), snack.end());
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