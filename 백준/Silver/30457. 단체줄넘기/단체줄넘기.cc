#include <iostream>
#include <vector>

using namespace std;

void Solution() {
    int N, n, ans = 0;
    vector<int> num(1001, 0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;

        if (num[n] >= 2) continue;

        num[n]++;
        ans++;
    }

    cout << ans;
}

void Solve() {
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
