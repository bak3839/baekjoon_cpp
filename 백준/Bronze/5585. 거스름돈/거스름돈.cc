#include <iostream>
#include <vector>

using namespace std;

int N;

void Solution() {
    int money[6] = { 500, 100, 50, 10, 5, 1 };
    int rest = 1000 - N, ans = 0;

    for (int i = 0; i < 6; i++) {
        ans += rest / money[i];
        rest -= (rest / money[i]) * money[i];
    }
    cout << ans;
}

void Input() {
    cin >> N;
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
