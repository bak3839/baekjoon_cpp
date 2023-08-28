#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N;

void Solution() {
    ll prev1 = 1, prev2 = 2;

    for (int i = 3; i <= N; i++) {
        ll tmp1 = prev1, tmp2 = prev2;

        prev1 = tmp2 % 10;
        prev2 = (tmp1 + prev2) % 10;
    }

    cout << prev2;
}

void Input() {
    cin >> N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
