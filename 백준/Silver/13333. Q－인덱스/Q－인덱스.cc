#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> cnt;

void Solution() {
    int ans = 0;

    for (int k = 0; k <= N; k++) {
        for (int i = 0; i < N; i++) {
            if (cnt[i] >= k && k <= N - i && N - k <= i + 1) ans = k;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    cnt.resize(N);

    for (int i = 0; i < N; i++)
        cin >> cnt[i];

    sort(cnt.begin(), cnt.end());
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}