#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> cat;

void Solution() {
    int L = 0, R = N - 1, ans = 0;

    while (L < R) {
        if (cat[L] + cat[R] <= K) {
            L++; R--;
            ans++;
        }
        else R--;
    }

    cout << ans;
}

void Input() {
    cin >> N >> K;

    cat.resize(N);

    for (int i = 0; i < N; i++)
        cin >> cat[i];
    sort(cat.begin(), cat.end());
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