#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> tip;

void Solution() {
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int res = tip[i] - i;

        if (res <= 0) break;

        ans += res;
    }

    cout << ans;
}

void Input() {
    cin >> N;

    tip.resize(N);

    for (int i = 0; i < N; i++)
        cin >> tip[i];
    sort(tip.begin(), tip.end(), greater<int>());
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
