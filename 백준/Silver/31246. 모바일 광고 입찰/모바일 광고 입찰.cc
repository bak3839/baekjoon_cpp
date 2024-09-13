#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> res;

void Solution() {
    sort(res.begin(), res.end());

    int index = 0, ans = 0;

    while (K != 0 && index < N) {
        if (res[index] > 0) {
            ans = res[index];
        }

        K--;
        index++;
    }

    cout << ans;
}

void Input() {
    int a, b;
    cin >> N >> K;

    res.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        res[i] = b - a;
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}