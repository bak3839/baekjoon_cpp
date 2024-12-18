#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> v;

void Solution() {
    int L = 0, R = N - 1, ans = 200000001, sum;

    while (L < R) {
        sum = v[L] + v[R];

        if (abs(sum) < abs(ans)) {
            ans = sum;
            if (sum == 0) break;
        }

        if (sum < 0) L++;
        else R--;
    }

    cout << ans;
}

void Input() {
    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
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